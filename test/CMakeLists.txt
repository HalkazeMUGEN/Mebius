cmake_minimum_required (VERSION 3.12)

file (GLOB src src/*.cpp src/*.c)

set (CALLER_EXE Caller)

add_executable (
	${CALLER_EXE}
	${src}
)

find_package (${PROJECT_NAME} REQUIRED)
target_compile_features (${CALLER_EXE} PRIVATE cxx_std_20)
target_link_libraries (${CALLER_EXE} PRIVATE ${PROJECT_NAME}::${PROJECT_NAME})
