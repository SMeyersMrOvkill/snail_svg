#ifndef SVG_HPP
#define SVG_HPP 1

#include <snail/ssvg.hpp>

#include <SDL2/SDL.h>
#include <vector>
#include <string>

use namespace std;

namespace Snail {

    class Svg {
    public:
    Svg();
    ~Svg();

    int init(int width, int height);
    void disable();
    void load(const string& path)
    {
        SSvg* svg = SSvg::load(path);
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
        SDL_PollEvent(this->event);
        bool quit = false;
        while (!quit) {
            while (SDL_PollEvent(this->event)) {
                if (this->event->type == SDL_QUIT) {
                    quit = true;
                }
            }
            
            SDL_RenderClear(this->renderer);
        }
    }

    private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event* event;
    //TTF_Font* font;
    SSvg* root;
    };

}

#endif