#pragma once
#include "Unit.hpp"

class battery: public Unit{
    SDL_Rect src, mover;
    public:
    battery(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);

    void draw();
    
};