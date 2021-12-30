#pragma once
#include "Unit.hpp"

class Vehicle: public Unit{
    SDL_Rect src, mover;
    public:
    Vehicle(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);

    void draw();
    
};