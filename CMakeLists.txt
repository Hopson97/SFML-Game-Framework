cmake_minimum_required(VERSION 3.0)

#Enable debug symbols
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose debug or release" FORCE)
endif()

project(SFML_Framework)

#Add the files
add_executable(framework
    ./Source/*
    ./Source/GUI/*
    ./Source/ResourceHolder/*
    ./Source/ResourceManager/*
    ./Source/States/*
    ./Source/Util/*
)

#Add libraries
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML REQUIRED graphics network audio window system)


