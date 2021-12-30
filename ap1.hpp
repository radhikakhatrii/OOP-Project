// Inherit from Unit class
#pragma once
#include "Unit.hpp"
#pragma once
class ap1 : public Unit
{
    SDL_Rect src, mover;

public:
    ap1(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov);
    void move(int &x);
    void draw();
};