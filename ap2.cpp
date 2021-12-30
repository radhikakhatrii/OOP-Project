#include "ap2.hpp"

ap2::ap2(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Unit(rend, ast), mover(mov)
{
    src = {33, 299, 390, 154};
}
void ap2::draw()
{
    Unit::draw(src, mover);
    mover.x += 3;
}