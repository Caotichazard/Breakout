#ifndef BALL
#define BALL
#include <vector>
#include "raylib.h"
#include "blocks.h"
#include "player.h"
#include "math.h"

using namespace std;

class ball{
    private:
        Vector2 pos, acc{1.0,1.0};
        float vel=5.0,rad=10.0;
    public:

        ball(float x, float y){
            pos.x = x;
            pos.y = y;
        }
        void atualiza(){
            pos.x = pos.x + acc.x*vel;
            pos.y = pos.y + acc.y*vel;
            DrawCircle(pos.x,pos.y,rad,MAROON);
        }
        void collision(player *p){
            
                /*int recCenterX = (int)(p->getRectX() + p->getRectW()/2.0f);
                int recCenterY = (int)(p->getRectY() + p->getRectH()/2.0f);

                float dx = (float)fabs(pos.x - recCenterX);
                float dy = (float)fabs(pos.y - recCenterY);

                if (dx > (p->getRectW()/2.0f + rad)) { return false; }
                if (dy > (p->getRectH()/2.0f + rad)) { return false; }

                if (dx <= (p->getRectW()/2.0f) && dy <= (p->getRectH()/2.0f)) { 
                    if(dy < p->getRectH()/2.0f){
                        acc.y *= -1;
                    }
                    if(dy == p->getRectH()/2.0f){
                        acc.x *=-1;
                    }
                }
                

                float cornerDistanceSq = (dx - p->getRectW()/2.0f)*(dx - p->getRectW()/2.0f) +
                                        (dy - p->getRectH()/2.0f)*(dy - p->getRectH()/2.0f);

                if(cornerDistanceSq <= (rad*rad)){

                }*/
                Vector2 r;
                r = p->getCenter();
                if(pos.y == r.y-p->getRectH()/2.0f || pos.y == r.y+p->getRectH()/2.0f){
                    if(CheckCollisionCircleRec(pos,rad,p->getRect())){
                        acc.y *= -1;
                    }
                }
                if(pos.x == r.x-p->getRectW()/2.0f || pos.x == r.x+p->getRectW()/2.0f){
                    if(CheckCollisionCircleRec(pos,rad,p->getRect())){
                        acc.x *= -1;
                    }
                }
        }
        void collision(vector<blocks> *bs){
                //blocks bc=b;
                for(int i=0;i< bs->size();i++){
                    blocks b= bs->at(i);
                    Vector2 r;
                    r = b.getCenter();
                    if(pos.y == r.y-b.getRectH()/2.0f-5.0f || pos.y == r.y+b.getRectH()/2.0f+5.0f){
                        if(CheckCollisionCircleRec(pos,rad,b.getRect())){
                            acc.y *= -1;
                            bs->erase(bs->begin()+i);
                        }
                    }
                    else if(pos.x == r.x-b.getRectW()/2.0f-5.0f || pos.x == r.x+b.getRectW()/2.0f+5.0f){
                        if(CheckCollisionCircleRec(pos,rad,b.getRect())){
                            acc.x *= -1;
                            bs->erase(bs->begin()+i);
                        }
                    }
                }
                
            
        }
        void collision(){
            if(pos.x>490 || pos.x < 10){
                acc.x *= -1;
            }
            if(pos.y>590 || pos.y <10){
                acc.y *= -1;
            }
        }
        
};


#endif