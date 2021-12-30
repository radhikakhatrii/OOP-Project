#include "boat1.hpp"

boat1::boat1(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Unit(rend, ast), mover(mov)
{
    src = {409, 22, 418, 317};
}
void boat1::draw()
{
    Unit::draw(src, mover);
    //mover.x += 4;
}

void boat1::move(int &x){
    int temp=x;
    if(temp==0){
        mover.x+=8;
        temp=2;
    }
    else if(temp==1){
        mover.x-=4;
        temp=2;
    }
}