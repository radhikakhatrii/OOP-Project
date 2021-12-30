#include "ap3.hpp"

ap3::ap3(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Unit(rend, ast), mover(mov)
{
    src = {64, 546, 173, 102};
}
void ap3::draw()
{
    Unit::draw(src, mover);
    mover.x += 2;
}