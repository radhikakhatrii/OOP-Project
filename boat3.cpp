#include "boat3.hpp"

boat3::boat3(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Unit(rend, ast), mover(mov)
{
    src = {40, 935, 249, 166};
}
void boat3::draw()
{
    Unit::draw(src, mover);
    mover.x += 5;
}