//objetivo, fazer blocos com o tempo e destruir mais rapido o bloco
/*
    TODO:
        -Fix collisions(?)
        -
*/

#include "game.h"


using namespace std;

int main(){
    game g;
    
    
    int screenH = 600;
    int screenW = 800;


    InitWindow(screenW,screenH,"Breakout");
    SetTargetFPS(120);
    
    
    
    
    g.run();

    CloseWindow();
    
}