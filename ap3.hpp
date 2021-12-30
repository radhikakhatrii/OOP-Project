// Inherit from Unit class
#include "Unit.hpp"
#pragma once
class ap3 : public Unit
{
    SDL_Rect src, mover;

public:
    ap3(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov);

    void draw();
};