cmake_minimum_required(VERSION 3.2)

set(PROJECT_NAME_STR grishagin_functions)
project (${PROJECT_NAME_STR})

file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/grishagin_function.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)

add_library(${PROJECT_NAME_STR} STATIC ${SRC_FILES})
target_include_directories(${PROJECT_NAME_STR} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME_STR} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

pybind11_add_module(py_${PROJECT_NAME_STR} ${SRC_FILES} src/py_grishagin.cpp)
target_include_directories(py_${PROJECT_NAME_STR} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(py_${PROJECT_NAME_STR} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

if(IS_GNU_COMPILER)
  target_compile_options(${PROJECT_NAME_STR} PUBLIC -fPIC -std=c++11)
endif()
