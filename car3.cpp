#include "car3.hpp"

car3::car3(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Unit(rend, ast), mover(mov)
{
    src = {15, 1438, 386, 138};
}
void car3::draw()
{
    Unit::draw(src, mover);
    mover.x += 5;
}