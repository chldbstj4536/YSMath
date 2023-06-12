cmake_minimum_required(VERSION 3.25)

project(YSMath)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(target_name YSMath)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.cpp)

# target 설정
add_library(${target_name} ${sources})

message(STATUS ${CMAKE_INSTALL_PREFIX})

execute_process(COMMAND ${CMAKE_COMMAND} -S ${CMAKE_SOURCE_DIR}/submodules/YSDefine -B ${CMAKE_BINARY_DIR}/YSDefine -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX})
execute_process(COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR}/YSDefine --target install)

target_include_directories(YSMath
    PRIVATE ./inc
    PUBLIC ./out/inc)

# 설치
install(DIRECTORY ./inc/
    DESTINATION ${CMAKE_INSTALL_PREFIX}/YSMath/inc)
install(TARGETS    ${target_name} 
    DESTINATION ${CMAKE_INSTALL_PREFIX}/YSMath/lib)