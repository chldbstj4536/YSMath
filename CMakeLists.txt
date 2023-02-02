cmake_minimum_required(VERSION 3.25)

project(YSMath)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(target_name YSMath)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_library(${target_name} STATIC ${sources})
add_subdirectory(submodules/YSDefine)

if(MSVC)

elseif(${CMAKE_CXX_COMPILER_ID} MATCHES GNU)

else()
    message(FATAL_ERROR "No supoort this compiler currently")
endif()

target_include_directories(${target_name} PRIVATE ${PROJECT_SOURCE_DIR}/inc)
target_compile_features(${target_name} PUBLIC cxx_std_20)