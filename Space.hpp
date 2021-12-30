// Make composition of TankBody and TankTurret objects in Tank class
#include "ap1.hpp"
#include "ap2.hpp"
#include "ap3.hpp"
#pragma once

class Space : public ap1, public ap2, public ap3
{
    SDL_Rect src, mover;

public:
    int y;
    Space(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov);
    void draw();
};