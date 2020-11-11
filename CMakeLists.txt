cmake_minimum_required(VERSION 3.17)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)
add_compile_options( -Wall -Wextra -Werror )


set(INCLUDE_DIRS srcs/
        srcs/iterator/
        srcs/allocator/
        srcs/list/)

include_directories(${INCLUDE_DIRS})

set(SRCS srcs/list/list.hpp srcs/allocator/allocator.hpp srcs/ft.hpp srcs/iterator/iterator.hpp)
add_executable(ft_containers main.cpp ${SRCS})

add_library(testlib ${SRCS} main.cpp)
add_subdirectory(unit_tests)