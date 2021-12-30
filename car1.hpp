// Inherit from Unit class
#include "Unit.hpp"
#pragma once
class car1 : public Unit
{
    SDL_Rect src, mover;

public:
    car1(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov);
    void move(int &x);
    void draw();
};