cmake_minimum_required(VERSION 3.12)

set(CMAKE_BUILD_PARALLEL_LEVEL 20)

project(D2CtrlMove)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE sources
        "src/*.cpp"
        "include/*.hpp"
        "src/*.cc"
        "include/*.h"
        "tests/*.cpp")

add_library(D2CtrlMove SHARED ${sources})

set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /W3 /GR /EHsc")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd /Zi /Ob0 /Od /RTC1")
set(CMAKE_CXX_FLAGS_MINSIZEREL "/MT /O1 /Ob1 /DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "/MT /O2 /Ob2 /DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MT /Zi /O2 /Ob1 /DNDEBUG")

add_compile_definitions(WIN32_LEAN_AND_MEAN)

target_compile_options(D2CtrlMove PRIVATE /wd4068)
target_compile_options(D2CtrlMove PRIVATE /wd4293)
target_compile_options(D2CtrlMove PRIVATE /wd4996)

target_include_directories(D2CtrlMove PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(D2CtrlMove PRIVATE wsock32 ws2_32)

#MinHook
add_subdirectory(vendor/minhook)
target_link_libraries(D2CtrlMove PRIVATE minhook)
set_target_properties(minhook PROPERTIES
	MAP_IMPORTED_CONFIG_MINSIZEREL Release
	MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release
)

set_target_properties(D2CtrlMove PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/install)
