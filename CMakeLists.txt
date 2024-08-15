cmake_minimum_required(VERSION 3.16)

project(SimpleCalculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SimpleCalculator main.cpp)

include(GNUInstallDirs)
install(TARGETS SimpleCalculator
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
