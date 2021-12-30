#include "Streets.hpp"
#include<iostream>
void Streets::drawObjects(){
    // call draw functions of all the objects here
    for (Space *s1: spaces){
    s1->y=z;
    s1->draw();
    }
    for (River *r1: rivers){
    r1->y=z;
    r1->draw();
    }
    for (Road *ro1: roads){
    ro1->y=z;
    ro1->draw();
    }
}

void Streets::createObject(int x, int y, int u){
    SDL_Rect mov = {20, 120, 300, 100};
    if(u==1){
    Space *next_space = new Space(gRenderer, assets, mov);
    spaces.push_back(next_space);
    }
    else if(u==2){
    River *next_river = new River(gRenderer, assets, mov);
    rivers.push_back(next_river);
    std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
    }
    else if(u==3){
    Road *next_road = new Road(gRenderer, assets, mov);
    roads.push_back(next_road);
    std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
    }
}

Streets::Streets(SDL_Renderer *renderer, SDL_Texture *asst):gRenderer(renderer), assets(asst){
}

void Streets::fire(){
    cout << "F key is pressed" <<endl; 
    // provide code to fire all of the tanks.
}

void Streets::updateAssets(SDL_Texture *asset)
{
    assets = asset;
}
