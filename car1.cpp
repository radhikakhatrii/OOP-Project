#include "car1.hpp"

car1::car1(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Unit(rend, ast), mover(mov)
{
    src = {0, 1181, 356, 118};
}
void car1::draw()
{
    Unit::draw(src, mover);
    //mover.x += 4;
}

void car1::move(int &x){
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