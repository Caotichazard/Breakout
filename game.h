#ifndef GAME
#define GAME


#include <vector>
#include <iostream>
#include <string>
#include "raylib.h"
#include "player.h"
#include "ball.h"
#include "blocks.h"

using namespace std;


class game{
    private:
        int score = 0;
        ball b1;
        player p1;
        vector<blocks> bs;
        bool gamePaused=false;
    public:
    void run(){
        gameSetup();
                
        while ( !WindowShouldClose()){
            
            BeginDrawing();
            ClearBackground(BLACK);
            if(!gamePaused){
                gameUpdate();
                gameDraw();
                
                if(bs.size()==0){
                    levelReset();
                }
                if(IsKeyPressed(KEY_DOWN)){
                    
                    gamePaused = true;
                }
            }else{
                gameDraw();
                DrawText("PAUSE",300, 300, 18, RAYWHITE);
                if(IsKeyPressed(KEY_DOWN)){
                    gamePaused = false;
                }
            }
            EndDrawing();
        }

    }

    void gameSetup(){
        p1.setup(250,540);
        initBall(b1,p1);
        bs=createBlocks(1);
        
    }

    void gameUpdate(){
        
        p1.update();
        b1.update();
        
        
        if(b1.getVel()==0){
            initBall(b1,p1);
            if(IsKeyPressed(KEY_UP)){
               launchBall(b1);
            }
        }
        b1.collision(&p1);
        if(b1.collision(&bs)){
            addScore(b1.getScore());
        }
        b1.collision();
    }

    void levelReset(){

        if(score/10000<3){
            bs=createBlocks(1+score/10000);
        }else{bs=createBlocks(3);}
        initBall(b1,p1);
        
    }

    void gameDraw(){
        b1.draw();
        p1.draw();
        for (int i=0;i<bs.size(); i++){
                bs[i].draw();
        }
        printScore(score);
        printBorders();
    }
    vector<blocks> createBlocks(int level){
        vector<blocks> bs;
        
        
        blocks b;
        for (int i=0;i<8; i++){
            for(int j=0; j < 8; j++){
                b.set(40+i*55,50+26*j,level);
                bs.push_back(b);
            }
        }
        return bs;

    }

    void initBall(ball &b, player &p){
        b.setPos(p.getRectX()+35,p.getRectY()-12);
        b.setVel(0);
    }

    void launchBall(ball &b){
        b.setVel(300);
    }

    void addScore(int s){
        score += s;
    }
    void printScore(int score){
        string s = to_string(score);
        string b ="Score: ";
        string c = b+s;
        char const * text=c.c_str();
        DrawText(text,600, 200, 18, RAYWHITE);
        
        
    }

    void printBorders(){
        DrawRectangleLines(0,0,500,600,RAYWHITE);
        DrawRectangleLines(500,0,300,600,RAYWHITE);
    }

};




#endif