cmake_minimum_required (VERSION 3.12)

project (Mebius VERSION 0.1.0 LANGUAGES CXX)

file (GLOB src src/*.cpp src/*.c)
file (GLOB include include/*.hpp include/*.h)

add_library (
	${PROJECT_NAME} SHARED
	${src}
	${include}
)
add_library (${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_compile_features (${PROJECT_NAME} PRIVATE cxx_std_20)
target_compile_definitions (
	${PROJECT_NAME}
	PRIVATE
	MEBIUS
	MEBIUS_EXPORTS
	WIN32
	_WINDOWS
	_USRDLL
	_WINDLL
	UNICODE
	_UNICODE
	$<$<CONFIG:Debug>: 
		_DEBUG
		DEBUG
	>
	$<$<CONFIG:Release>:
		NDEBUG
	>
)

target_compile_options (
	${PROJECT_NAME}
	PRIVATE
	/W4
	/analyze-
	/arch:AVX
	/diagnostics:column
	/EHsc
	/FC
	/fp:precise
	/Gd
	/Gm-
	/GS
	/nologo
	/Oy-
	/permissive-
	/sdl
	/utf-8
	/WX-
	/Yupch.h
	/Zc:forScope
	/Zc:inline
	/Zc:wchar_t
	$<$<CONFIG:Debug>:
		/FP"build/x86-debug/Mebius.pch"
		/GR
		/JMC
		/MDd
		/Ob0
		/Od
		/RTC1
		/ZI
	>
	$<$<CONFIG:Release>:
		/FP"build/x86-release/Mebius.pch"
		/GA
		/GL
		/GR-
		/Gy
		/guard:cf-
		/MD
		/O1
		/Oi
		/Os
	>
)
target_link_options (
	${PROJECT_NAME}
	PRIVATE
	/DLL
	/DYNAMICBASE
	/MACHINE:X86
	/NOLOGO
	/NXCOMPAT
	/SAFESEH
	/SUBSYSTEM:WINDOWS
	$<$<CONFIG:Debug>:
		/DEBUG
		/INCREMENTAL
		/OPT:NOREF
	>
	$<$<CONFIG:Release>:
		/LTCG:incremental
		/OPT:ICF
		/OPT:REF
	>
)

target_include_directories (
	${PROJECT_NAME}
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories (
	${PROJECT_NAME}
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/share>
	$<INSTALL_INTERFACE:include>
)

install (
	TARGETS ${PROJECT_NAME}
	EXPORT ${PROJECT_NAME}-config
	ARCHIVE DESTINATION lib
	PUBLIC_HEADER DESTINATION include
)

install (
	EXPORT ${PROJECT_NAME}-config
	NAMESPACE ${PROJECT_NAME}::
	DESTINATION cmake
)

install (
	DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/share/
	DESTINATION include
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file (
	${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
	COMPATIBILITY SameMajorVersion
)

install (
	FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
	DESTINATION cmake
)
