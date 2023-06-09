cmake_minimum_required(VERSION 3.25)

project(YSMath)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(target_name YSMath)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.cpp)

# target 설정
add_library(${target_name} ${sources})

message(STATUS ${CMAKE_INSTALL_PREFIX})
add_subdirectory(submodules/YSDefine)

if (TEST_FLAG)

endif()

# 설치
install(DIRECTORY   ./inc
    DESTINATION ${CMAKE_INSTALL_PREFIX})
install(TARGETS    ${target_name} 
    DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)