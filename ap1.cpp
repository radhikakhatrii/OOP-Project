#include "ap1.hpp"

ap1::ap1(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Unit(rend, ast), mover(mov)
{
    src = {48, 52, 209, 94};
}
void ap1::draw()
{
    Unit::draw(src, mover);
}

void ap1::move(int &x){
    int temp=x;
    if(temp==0){
        mover.x+=8;
        temp=2;
    }
    else if(temp==1){

        mover.x-=5;
        temp=2;
    }
}
