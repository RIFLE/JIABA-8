#cmake_minimum_required(VERSION 3.4.1)

#project(LAB8)

# ${PROJECT_NAME}
#set(CMAKE_CXX_STANDART 11)
# or
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -02")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -02")


#set(SOURCES main.cpp functions.cpp module.h)
#file(GLOB
    #        CPPS "*.cpp")
#add_executable(${PROJECT_NAME} ${CPPS})
#add_executable(${PROJECT_NAME} ${SOURCES})
#add_executable(${PROJECT_NAME} main.cpp functions.cpp module.h)

cmake_minimum_required(VERSION 3.0)

project(lab)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CPPS main.cpp
          functions.cpp)

add_executable(${PROJECT_NAME} ${CPPS})
