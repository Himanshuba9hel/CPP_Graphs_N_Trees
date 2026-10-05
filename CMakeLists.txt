cmake_minimum_required(VERSION 3.16)

project(CPP_Graphs_N_Trees LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CPP_Graphs_N_Trees main.cpp
    Constructors/graph_constructor.h Constructors/graph_constructor.cpp
    Constructors/tree_constructor.h Constructors/tree_constructor.cpp
    Constructors/node.h)

include(GNUInstallDirs)
install(TARGETS CPP_Graphs_N_Trees
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
enable_testing()
add_subdirectory(Test_Cases)
