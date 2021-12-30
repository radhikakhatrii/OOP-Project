#include "boat2.hpp"

boat2::boat2(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Unit(rend, ast), mover(mov)
{
    src = {95, 683, 257, 161};
}
void boat2::draw()
{
    Unit::draw(src, mover);
    mover.x += 5;
}