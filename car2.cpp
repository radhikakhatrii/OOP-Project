#include "car2.hpp"

car2::car2(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Unit(rend, ast), mover(mov)
{
    src = {462, 1163, 320, 128};
}
void car2::draw()
{
    Unit::draw(src, mover);
    mover.x += 5;
}