cmake_minimum_required(VERSION 3.10)
project(ssvg)

include_directories(include)

file(GLOB SnailSvgSrc
    "src/*.cpp"
)

add_library(ssvg SHARED ${SnailSvgSrc})

# Link the SDL2 library to the build
target_link_libraries(ssvg -lSDL2 ${SDL2_LIBRARY})