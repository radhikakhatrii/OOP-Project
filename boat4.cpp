#include "boat4.hpp"

boat4::boat4(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Unit(rend, ast), mover(mov)
{
    src = {399, 895, 198, 204};
}
void boat4::draw()
{
    Unit::draw(src, mover);
    mover.x += 5;
}