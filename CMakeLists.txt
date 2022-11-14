cmake_minimum_required(VERSION 3.22)
project(images LANGUAGES CXX)

find_package(OpenMP REQUIRED)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors -fopenmp)

set(CMAKE_CXX_FLAGS_RELEASE "-march=native")

add_subdirectory(common)
add_subdirectory(aos)
add_subdirectory(soa)
add_executable(img-aos imageaos.cpp)
add_executable(img-soa imagesoa.cpp)

target_link_libraries(img-aos aos common OpenMP::OpenMP_CXX)
target_link_libraries(img-soa soa common OpenMP::OpenMP_CXX)
target_include_directories(img-aos PUBLIC common aos)
target_include_directories(img-soa PUBLIC common soa)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()
add_subdirectory(utest)
