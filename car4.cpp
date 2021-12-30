#include "car4.hpp"

car4::car4(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Unit(rend, ast), mover(mov)
{
    src = {488, 1473, 368, 114};
}
void car4::draw()
{
    Unit::draw(src, mover);
    mover.x += 5;
}