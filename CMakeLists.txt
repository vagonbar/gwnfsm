# gwnfsm : GWN FSM, an Extended Finite State Machine

	
cmake_minimum_required(VERSION 2.8.9)
project (gwnfsm)


# add support for standard C11++
macro(use_cxx11)
  if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
      set (CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")
    endif ()
  else ()
    set (CMAKE_CXX_STANDARD 11)
  endif ()
endmacro(use_cxx11)

use_cxx11()

file(GLOB SOURCES "*.cpp")

add_executable(fsm_test ${SOURCES})
