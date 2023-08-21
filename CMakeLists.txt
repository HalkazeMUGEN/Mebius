cmake_minimum_required (VERSION 3.15)

project (Mebius VERSION 0.1.0 LANGUAGES CXX)

option(ZYDIS_BUILD_TOOLS "" OFF)
option(ZYDIS_BUILD_EXAMPLES "" OFF)
add_subdirectory("deps/zydis" EXCLUDE_FROM_ALL)

file (GLOB src src/*.cpp src/*.c)
file (GLOB include include/*.hpp include/*.h)

add_library (
	${PROJECT_NAME} SHARED
	${src}
	${include}
)
add_library (${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PRIVATE Zydis)

target_compile_features (${PROJECT_NAME} PUBLIC cxx_std_20)
target_compile_definitions (
	${PROJECT_NAME}
	PRIVATE
	MEBIUS_EXPORT
	UNICODE
	_UNICODE
	$<$<CONFIG:Debug>: 
		_DEBUG
		DEBUG
	>
)

target_compile_options (
	${PROJECT_NAME}
	PRIVATE
	/W4
	/arch:AVX
	/fp:fast
	/GS
	/GT
	/MP
	/nologo
	/Oi
	/Qpar
	/utf-8
	$<$<CONFIG:Debug>:
		/GR
		/JMC
		/MDd
		/Ob0
		/Od
		/RTC1
		/ZI
	>
	$<$<CONFIG:Release>:
		/GA
		/GL
		/GR-
		/Gy
		/guard:cf-
		/MT
		/Os
	>
)
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE "/NODEFAULTLIB:MSVCRT")

target_link_options (
	${PROJECT_NAME}
	PRIVATE
	/LTCG
	/nologo
	$<$<CONFIG:Debug>:
		/debug
		/opt:noref
	>
	$<$<CONFIG:Release>:
		/opt:ref
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

add_subdirectory(example/)