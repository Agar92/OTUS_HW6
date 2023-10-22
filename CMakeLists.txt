cmake_minimum_required(VERSION 3.15)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})
project(sparse_matrix LANGUAGES CXX VERSION ${PROJECT_VERSION})
configure_file(version.h.in version.h @ONLY)

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
set_target_properties(${PROJECT_NAME}
					  PROPERTIES
					  CXX_STANDARD 20
					  CXX_STANDARD_REQUIRED ON
)