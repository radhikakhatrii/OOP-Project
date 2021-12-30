#pragma once
#include "boat1.hpp"
#include "boat2.hpp"
#include "boat3.hpp"


class River : public boat1, public boat2, public boat3
{
    SDL_Rect src, mover;

public:
    int y;
    River(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov);
    void draw();
};