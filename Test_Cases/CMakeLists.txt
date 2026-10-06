cmake_minimum_required(VERSION 3.16)

project(CorrectConstruction LANGUAGES CXX)

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
    ../Constructors/GraphConstructor.cpp
    ../Constructors/TreeConstructor.cpp  # Add this line so CMake compiles it
)
# --- Include Directories ---
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_SOURCE_DIR}/../Constructors
)

add_executable(CorrectConstruction
    main.cpp tstCorrectConstruction.cpp
    ${PROJECT_SOURCES}
)
add_test(NAME CorrectConstruction COMMAND CorrectConstruction)

target_link_libraries(CorrectConstruction PRIVATE gtest gmock)

include(GNUInstallDirs)
install(TARGETS CorrectConstruction
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
