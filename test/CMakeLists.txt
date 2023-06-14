cmake_minimum_required(VERSION 3.25)

project(YSMathTest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 외부 프로젝트 설치
execute_process(COMMAND ${CMAKE_COMMAND} -S ./.. -B ./../build -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX})
execute_process(COMMAND ${CMAKE_COMMAND} --build ./../build --target install)

add_executable(YSMathTest main.cpp)

# VS에서 시작프로젝트 설정
if(MSVC)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT YSMathTest)
endif()

target_include_directories(YSMathTest
    PRIVATE ${CMAKE_INSTALL_PREFIX}/inc)

    message(STATUS ${CMAKE_INSTALL_PREFIX}/inc)

target_link_libraries(YSMathTest ${CMAKE_INSTALL_PREFIX}/lib/YSMath/YSMath.lib)