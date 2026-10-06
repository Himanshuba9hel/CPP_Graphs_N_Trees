cmake_minimum_required(VERSION 3.16)

project(CPP_Graphs_N_Trees LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Create a library for your shared source code and headers
add_library(ConstructorsLib
    Constructors/GraphConstructor.h Constructors/GraphConstructor.cpp
    Constructors/TreeConstructor.h Constructors/TreeConstructor.cpp
    Constructors/node.h
)

# 2. Add your main executable and link the library to it
add_executable(CPP_Graphs_N_Trees main.cpp)
target_link_libraries(CPP_Graphs_N_Trees PRIVATE ConstructorsLib)

include(GNUInstallDirs)
install(TARGETS CPP_Graphs_N_Trees
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

enable_testing()
add_subdirectory(TestCases)