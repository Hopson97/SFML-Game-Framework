cmake_minimum_required(VERSION 3.10)

#Set up project
project(GAME_NAME VERSION 1.0)

#Set executable
add_executable(${PROJECT_NAME}     
    src/main.cpp
    src/Game.cpp

    src/GUI/Button.cpp
    src/GUI/StackMenu.cpp
    src/GUI/Textbox.cpp
    src/GUI/Widget.cpp
    
    src/ResourceManager/ResourceHolder.cpp

    src/States/StatePlaying.cpp

    src/Util/Animation.cpp
    src/Util/FileUtil.cpp
    src/Util/FPSCounter.cpp
    src/Util/Maths.cpp
    src/Util/Maths.cpp
)

#Set C++17
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

#Set flags
if(MSVC)
  	target_compile_options(${PROJECT_NAME} PRIVATE 
    	/W4 /WX)
else()
  	target_compile_options(${PROJECT_NAME} PRIVATE 
		-Wall -Wextra -pedantic -Werror)		#Warning flags
endif()

#Set module path
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

#Find libraries
find_package(Threads)
find_package(OpenGL REQUIRED)
find_package(SFML REQUIRED audio network graphics window system)

add_subdirectory(deps/imgui)
add_subdirectory(deps/imgui_sfml)


#Finally
target_link_libraries(${PROJECT_NAME} 
    imgui
    imgui_sfml
    Threads::Threads 
    ${OPENGL_LIBRARIES} 
    ${SFML_LIBRARIES} 
    ${SFML_DEPENDENCIES}
)
