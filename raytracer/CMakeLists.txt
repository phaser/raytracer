cmake_minimum_required (VERSION 2.8)
set (PROJ_NAME "raytracer")
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${KRAL_PATH})
project (${PROJ_NAME})
include (main)

module(${PROJ_NAME}
    DEPENDENCY lodepng  20120729  
    DEPENDENCY glm      0.9.6.3 
)
