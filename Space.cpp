#include "Space.hpp"

Space::Space(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mover) : ap1::ap1(rend, ast, {mover.x, mover.y, 150, 100}), ap2::ap2(rend, ast, {mover.x, mover.y+100, 150, 100}), ap3::ap3(rend, ast, {mover.x, mover.y+230, 150, 100})

{
}

void Space::draw()
{
    ap1::draw();
    ap2::draw(); 
    ap3::draw();
    ap1::move(y);
}