// Inherit from Unit class
#include "Unit.hpp"
#pragma once
class boat4 : public Unit
{
    SDL_Rect src, mover;

public:
    boat4(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov);

    void draw();
};