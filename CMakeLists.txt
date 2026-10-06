cmake_minimum_required(VERSION 3.16)

project(CPP_Graphs_N_Trees LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CPP_Graphs_N_Trees main.cpp
    Constructors/GraphConstructor.h Constructors/GraphConstructor.cpp
    Constructors/TreeConstructor.h Constructors/TreeConstructor.cpp
    Constructors/node.h)

include(GNUInstallDirs)
install(TARGETS CPP_Graphs_N_Trees
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
# enable_testing()
# add_subdirectory(Test_Cases)
