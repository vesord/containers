cmake_minimum_required(VERSION 3.17)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)
add_compile_options( -Wall -Wextra -Werror -Wconversion -Wno-unused)


set(INCLUDE_DIRS srcs)

include_directories(${INCLUDE_DIRS})

set(SRCS srcs/list.hpp srcs/allocator.hpp srcs/ft.hpp srcs/iterator.hpp srcs/vector.hpp srcs/map.hpp)
add_executable(ft_containers main.cpp ${SRCS} srcs/stack.hpp)

add_library(testlib ${SRCS} main.cpp)
add_subdirectory(unit_tests)