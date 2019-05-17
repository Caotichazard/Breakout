#ifndef BLOCKS
#define BLOCKS
#include "raylib.h"

class blocks{
    private:
        Rectangle rect;
        float w=50,h=20;
    public:
        blocks(){

        }
        void set(float x,float y){
            rect.x = x;
            rect.y = y;
            rect.width =w;
            rect.height=h;
        }
        void atualiza(){
            DrawRectangle(rect.x,rect.y,rect.width,rect.height,ORANGE);
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
};


#endif