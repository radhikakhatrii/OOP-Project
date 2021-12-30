// Inherit from Unit class
#include "Unit.hpp"
#pragma once
class boat1 : public Unit
{
    SDL_Rect src, mover;

public:
    boat1(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov);
    void move(int &x);
    void draw();
};