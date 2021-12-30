// Inherit from Unit class
#include "Unit.hpp"
#pragma once
class car2 : public Unit
{
    SDL_Rect src, mover;

public:
    car2(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov);

    void draw();
};