// Inherit from Unit class
#include "Unit.hpp"
#pragma once
class ap2 : public Unit
{
    SDL_Rect src, mover;

public:
    ap2(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov);

    void draw();
};