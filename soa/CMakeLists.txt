find_package(OpenMP REQUIRED)
add_library(soa bitmap_soa.cpp)
target_link_libraries(soa common OpenMP::OpenMP_CXX)
target_include_directories(soa PUBLIC ..)
