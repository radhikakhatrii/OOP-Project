#include "River.hpp"

River::River(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mover) : boat1::boat1(rend, ast, {mover.x, mover.y+250, 150, 100}), boat2::boat2(rend, ast, {mover.x, mover.y+300, 150, 100}), boat3::boat3(rend, ast, {mover.x, mover.y+370, 150, 100})

{
}

void River::draw()
{
    boat1::draw();
    boat2::draw(); 
    boat3::draw();
    boat1::move(y);
}