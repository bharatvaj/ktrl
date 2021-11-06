cmake_minimum_required(VERSION 3.20)

project(ktrl VERSION 0.0.1 DESCRIPTION "Library for 'kontrolling' your input devices with other input devices")

set(KTRL_SRCS
    "src/KtrlInput.cpp"
    "src/KtrlInputController.cpp"
    "src/KtrlUInput.cpp"
)

add_library(ktrl ${KTRL_SRCS})

target_include_directories(ktrl PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/>
)

enable_testing()
add_subdirectory(test)