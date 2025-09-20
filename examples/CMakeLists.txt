cmake_minimum_required(VERSION 3.15)
project(mystl_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-O2 -Wall -Wextra -pedantic)

# Headers are at ../include relative to this folder
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

# Helper to add an example target if its source exists
function(add_optional_example name)
  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${name}.cpp)
    add_executable(${name} ${name}.cpp)
    target_include_directories(${name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
  endif()
endfunction()

add_optional_example(vector_example)
add_optional_example(stack_example)
add_optional_example(queue_example)
add_optional_example(deque_example)
add_optional_example(priority_queue_example)
add_optional_example(map_example)
add_optional_example(string_example)   # optional if string.h present
add_optional_example(set_example)      # optional if set.h present
add_optional_example(all_examples)
