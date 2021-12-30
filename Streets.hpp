#pragma once
#include<SDL.h>
#include "Vehicle.hpp"
#include "battery.hpp"
#include "ap1.hpp"
#include "ap2.hpp"
#include "Space.hpp"
#include "River.hpp"
#include "boat3.hpp"
#include "boat2.hpp"
#include "boat1.hpp"
#include "Road.hpp"
#include "car1.hpp"
#include "car2.hpp"
#include "car3.hpp"
#include<list>
using namespace std;

class Streets{
    list<Vehicle *> vehicles;
    list<Space *> spaces;
    list<River *> rivers;
    list<Road *> roads;
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    
    public:
    int z=2;
    Streets(SDL_Renderer *, SDL_Texture *);
    void drawObjects(); 
    void createObject(int, int, int);
    void fire();
    void updateAssets(SDL_Texture *);
};