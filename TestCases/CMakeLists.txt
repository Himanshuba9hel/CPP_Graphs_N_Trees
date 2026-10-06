cmake_minimum_required(VERSION 3.16)

project(CorrectConstruction LANGUAGES CXX)

# Match the main project's C++ standard (Changed from 14 to 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_SOURCE_DIR}/../Constructors
)

# Only compile the test-specific files here
add_executable(CorrectConstruction main.cpp tstCorrectConstruction.cpp)

# Link the shared ConstructorsLib from the parent directory
target_link_libraries(CorrectConstruction PRIVATE
    ConstructorsLib
    gtest
    gmock
)

add_test(NAME CorrectConstruction COMMAND CorrectConstruction)

include(GNUInstallDirs)
install(TARGETS CorrectConstruction
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)