#include "battery.hpp"    

    battery::battery(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), mover(mov){
        
        //battery0
        //src = {649, 700, 52, 97};
        //battery1
        //src = {494, 692, 52, 97};
        //battery2
        //src = {496, 509, 50, 97};
        //battery3
        //src = {649, 882, 51, 96};
        //battery4
        //src = {649, 882, 51, 96};
        
    }

    void battery::draw(){
        Unit::draw(src, mover);
        //mover.x+=10;
    }