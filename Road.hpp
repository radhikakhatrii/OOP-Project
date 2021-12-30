#include "car1.hpp"
#include "car2.hpp"
#include "car3.hpp"
#pragma once

class Road : public car1, public car2, public car3
{
    SDL_Rect src, mover;

public:
    int y;
    Road(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov);
    void draw();
    SDL_Rect Mover();
};