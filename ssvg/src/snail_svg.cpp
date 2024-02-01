#include <snail/svg.hpp>

#include <iostream>

namespace Snail {

    // namespace snail
    Svg::Svg() {
        
    }

    Svg::~Svg() {
        
    }

    int Svg::init(int width, int height) {
        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
            std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
            return 1;
        }

        window = SDL_CreateWindow("Hello World!", 100, 100, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
        if (window == nullptr) {
            std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return 1;
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer == nullptr) {
            SDL_DestroyWindow(window);
            std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return 1;
        }

        return 0;
    }

    void Svg::disable() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void Svg::set_root(void* root) {
        this->root = root;
    }

    void Svg::run() {
        SDL_Event e;
        bool quit = false;
        while (!quit) {
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) {
                    quit = true;
                }
            }
            
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
        }
    }

}