cmake_minimum_required(VERSION 3.2)

set(PROJECT_NAME_STR grishagin_functions)
project (${PROJECT_NAME_STR})

file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/grishagin_function.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)

add_library(${PROJECT_NAME_STR} STATIC ${SRC_FILES})
target_include_directories(${PROJECT_NAME_STR} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME_STR} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
set_property(TARGET ${PROJECT_NAME_STR} PROPERTY POSITION_INDEPENDENT_CODE ON)
set(PROBLEMS_LIBS ${PROBLEMS_LIBS} ${PROJECT_NAME_STR} PARENT_SCOPE)
