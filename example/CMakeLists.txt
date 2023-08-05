cmake_minimum_required (VERSION 3.15)

project (MebiusExample VERSION 0.1.0 LANGUAGES CXX)

add_library (
	${PROJECT_NAME} SHARED
	example.cpp
	example.hpp
)

find_package(Mebius REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Mebius)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
