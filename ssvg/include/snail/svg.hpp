#ifndef SVG_HPP
#define SVG_HPP 1

#include <snail/ssvg.hpp>

#include <SDL2/SDL.h>
#include <vector>
#include <string>

using namespace std;

namespace Snail {

    class Svg {
    public:
    Svg() {
        
    }

    ~Svg() {
        
    }

    int init(int width, int height)
    {
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

    void disable()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void load(const string& path)
    {
        SSvg* svg = SSvg::LoadPath(path);
        if(svg == nullptr)
        {
            return;
        }
        set_root(svg);
    }

    void set_root(SSvg* root)
    {
        this->root = root;
    }
    
    void run()
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        bool quit = false;
        while (!quit) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    quit = true;
                }
            }
            
            SDL_RenderClear(this->renderer);
        }
    }

    private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    //TTF_Font* font;
    SSvg* root;
    };

}

#endif