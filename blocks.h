#ifndef BLOCKS
#define BLOCKS
#include "raylib.h"
#include<iostream>

using namespace std;

class blocks{
    private:
        Rectangle rect;
        float w=50,h=20;
        int value = 200;
        int level;
    public:
        blocks(){

        }
        void set(float x,float y, int lvl){
            rect.x = x;
            rect.y = y;
            rect.width =w;
            rect.height=h;
            level = lvl;
        }
        void draw(){
            if(level==1){
                DrawRectangle(rect.x,rect.y,rect.width,rect.height,YELLOW);
            }
            if(level==2){
                DrawRectangle(rect.x,rect.y,rect.width,rect.height,ORANGE);
            }
            if(level>=3){
                DrawRectangle(rect.x,rect.y,rect.width,rect.height,RED);
            }
        }
        Rectangle getRect(){
            return rect;
        }
        float getRectX(){
            return rect.x;
        }
        float getRectY(){
            return rect.y;
        }
        float getRectW(){
            return rect.width;
        }
        float getRectH(){
            return rect.height;
        }
        Vector2 getCenter(){
            Vector2 center;
            center.x=(rect.x + rect.width/2.0f);
            center.y=(rect.y + rect.height/2.0f);
            return center;
        }

        int getValue(){
            return value;
        }
        int getLevel(){
            return level;
        }
        void setLevel(int i){
            level = i;
            cout << "Level of hit: " << level << endl;
        }
};


#endif