// Inherit from Unit class
#include "Unit.hpp"
#pragma once
class car3 : public Unit
{
    SDL_Rect src, mover;

public:
    car3(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov);

    void draw();
};