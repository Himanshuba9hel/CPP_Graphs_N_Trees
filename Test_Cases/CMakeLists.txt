cmake_minimum_required(VERSION 3.16)

project(Correct_Construction LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Safely pull Google Test for any OS
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

# 2. Scope the Windows-specific runtime fix strictly to the MSVC compiler
if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)

# --- Source Files ---
# Ensure these paths are correct relative to THIS CMakeLists.txt file
set(PROJECT_SOURCES
    ../Constructors/graph_constructor.cpp
    ../Constructors/tree_constructor.cpp  # Add this line so CMake compiles it
)
# --- Include Directories ---
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_SOURCE_DIR}/../Constructors
)

add_executable(Correct_Construction
    main.cpp tst_correct_construction.cpp
    ${PROJECT_SOURCES}
)
add_test(NAME Correct_Construction COMMAND Correct_Construction)

target_link_libraries(Correct_Construction PRIVATE gtest gmock)

include(GNUInstallDirs)
install(TARGETS Correct_Construction
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
