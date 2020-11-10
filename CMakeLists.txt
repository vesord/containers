cmake_minimum_required(VERSION 3.17)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)
add_compile_options( -Wall -Wextra -Werror )

include_directories(srcs
                    srcs/iterator
                    srcs/allocator
                    srcs/list)

add_executable(ft_containers main.cpp srcs/list/list.hpp srcs/allocator/allocator.hpp srcs/ft.hpp srcs/iterator/iterator.hpp)

add_subdirectory(unit_tests)