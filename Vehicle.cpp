#include "Vehicle.hpp"    

    Vehicle::Vehicle(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), mover(mov){
        //ap1
        //src = {48, 52, 209, 94}; 
        //ap2
        //src = {33, 299, 390, 154};
        //ap3
        //src = {64, 546, 173, 102};  
        //boat1
        //src = {409, 22, 418, 317};
        //boat2
        //src = {95, 683, 257, 161};
        //boat3 
        //src = {40, 935, 249, 166};
        //boat4 
        //src = {399, 895, 198, 204};
        //car1
        //src = {0, 1181, 356, 118}; 
        //car2
        //src = {462, 1163, 320, 128}; 
        //car3
        //src = {15, 1438, 386, 138}; 
        //car4 
        //src = {488, 1473, 368, 114};
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

    void Vehicle::draw(){
        Unit::draw(src, mover);
        // mover.x+=10;
    }