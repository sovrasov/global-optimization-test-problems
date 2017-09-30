cmake_minimum_required(VERSION 3.2)

macro(subdirlist result curdir)
  file(GLOB children RELATIVE ${curdir} ${curdir}/*)
  set(dirlist "")
  foreach(child ${children})
    if(IS_DIRECTORY ${curdir}/${child} AND NOT (${child} MATCHES "[.]"))
        list(APPEND dirlist ${curdir}/${child})
    endif()
  endforeach()
  set(${result} ${dirlist})
endmacro()

set(PROJECT_NAME_STR go_problems)

subdirlist(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR}/go-problems)
foreach(subdir ${SUBDIRS})
    add_subdirectory(${subdir})
endforeach()
