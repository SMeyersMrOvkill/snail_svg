project(ssvg_viewer)

file(GLOB SnailSvgViewerSrc
    "src/*.cpp"
)

include_directories(include ${SDL2_INCLUDE_DIRS} ../ssvg/include)

add_executable(SnailSvgViewer ${SnailSvgViewerSrc})

target_link_libraries(SnailSvgViewer -lSDL2 -L"${CMAKE_BINARY_DIR}" ssvg)