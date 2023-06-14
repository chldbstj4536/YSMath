cmake_minimum_required(VERSION 3.25)

project(YSMath)

# 외부 프로젝트 설치
execute_process(COMMAND ${CMAKE_COMMAND} -S ${CMAKE_SOURCE_DIR}/submodules/YSDefine -B ${CMAKE_BINARY_DIR}/YSDefine -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX})
execute_process(COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR}/YSDefine --target install)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# target 설정
file(GLOB_RECURSE sources CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_library(YSMath ${sources})

# target에 설치된 라이브러리 추가
target_include_directories(YSMath
    PRIVATE ./inc
    PUBLIC ./out/inc)

# 설치 관련 설정
install(DIRECTORY   ${CMAKE_SOURCE_DIR}/inc/
    DESTINATION ${CMAKE_INSTALL_PREFIX}/inc/YSMath)
install(TARGETS     YSMath 
    DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/YSMath)

# VS에서 시작프로젝트 설정
if(MSVC)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT YSMathTest)
endif()