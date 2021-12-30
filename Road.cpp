#include "Road.hpp"

Road::Road(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mover) : car1::car1(rend, ast, {mover.x, mover.y+370, 100, 70}), car2::car2(rend, ast, {mover.x+100, mover.y+390, 100, 70}), car3::car3(rend, ast, {mover.x, mover.y+410, 100, 70})

{
}

void Road::draw()
{
    car1::draw();
    car2::draw(); 
    car3::draw();
    car1::move(y);
}

SDL_Rect Road::Mover(){
    return mover;
}