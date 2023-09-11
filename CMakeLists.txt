cmake_minimum_required(VERSION 3.5)

project(OtelOtomasyonu LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(OtelOtomasyonu main.cpp)

include(GNUInstallDirs)
install(TARGETS OtelOtomasyonu
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
