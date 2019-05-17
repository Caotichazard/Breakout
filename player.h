#ifndef PLAYER
#define PLAYER
#include "raylib.h"
#include "pthread.h"

class player{
    private:   
        Rectangle r; 
        float vel=2.0;
    public:
        player(float x,float y){
            r.x = x;
            r.width = 75;
            r.height = 20;
            r.y = y; 
        }
        void atualiza(){
            
            if(IsKeyDown(KEY_LEFT) && r.x > 0){
                r.x -= vel;
            }else if(IsKeyDown(KEY_RIGHT) && r.x < 425){
                r.x += vel;
            }
            DrawRectangle(r.x,r.y,r.width,r.height,WHITE);
            
        }
        Rectangle getRect(){
            return r;
        }
        float getRectX(){
            return r.x;
        }
        float getRectY(){
            return r.y;
        }
        float getRectW(){
            return r.width;
        }
        float getRectH(){
            return r.height;
        }

        Vector2 getCenter(){
            Vector2 center;
            center.x=(r.x + r.width/2.0f);
            center.y=(r.y + r.height/2.0f);
            return center;
        }
};

#endif