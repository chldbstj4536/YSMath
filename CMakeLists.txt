cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(submodules/YSDefine)

target_include_directories(${target_name}
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
# PRIVATE
#     ${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_compile_features(${target_name} PUBLIC cxx_std_20)