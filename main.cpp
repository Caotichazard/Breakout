//objetivo, fazer blocos com o tempo e destruir mais rapido o bloco


#include <vector>
#include <iostream>
#include "raylib.h"
#include "player.h"
#include "ball.h"
#include "blocks.h"

using namespace std;

int main(){
    int screenH = 600;
    int screenW = 500;
    player p1((float)screenW/2,(float)screenH-screenH/10);
    ball b1((float)screenW/2,(float)screenH/2);

    vector<blocks> bs;
    
    
    blocks b;
    for (int i=0;i<8; i++){
        for(int j=0; j < 8; j++){
            b.set(40+i*55,50+26*j);
            bs.push_back(b);
        }
    }

    InitWindow(screenW,screenH,"Breakout");
    SetTargetFPS(60);
    
    
    
    while ( !WindowShouldClose()){
        b1.collision(&bs);
        for (int i=0;i<bs.size(); i++){
            bs[i].atualiza();
            //b1.collision(bs[i]);
        }
        p1.atualiza();
        b1.atualiza();
        b1.collision(&p1);
        b1.collision(&bs);
        b1.collision();

        BeginDrawing();
        ClearBackground(BLACK);
        
        
        EndDrawing();
    }

    CloseWindow();
    
}