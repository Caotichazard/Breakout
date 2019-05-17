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
            
            
                Vector2 r;
                r = p->getCenter();

                    bool hitLR =((pos.y >= r.y-p->getRectH()/2.0f && pos.y <= r.y+p->getRectH()/2.0f)&&CheckCollisionCircleRec(pos,rad,p->getRect()));
                    bool hitTD = ((pos.x >= r.x-p->getRectW()/2.0f+1.0f && pos.x <= r.x+p->getRectW()/2.0f+1.0f)&&CheckCollisionCircleRec(pos,rad,p->getRect()));
                    
                    if(hitTD&&!hitLR){
                        acc.y *= -1;
                        
                    }
                    else if(hitLR&&!hitTD){
                        acc.x *= -1;
                        
                    }
                    else if(hitTD&&hitLR){
                        acc.x *= -1;
                        acc.y *= -1;
                        
                    }
        }
        void collision(vector<blocks> *bs){
                //blocks bc=b;
                for(int i=0;i< bs->size();i++){
                    blocks p= bs->at(i);
                    Vector2 r;
                    r = p.getCenter();

                    bool hitLR =((pos.y >= r.y-p.getRectH()/2.0f && pos.y <= r.y+p.getRectH()/2.0f)&&CheckCollisionCircleRec(pos,rad,p.getRect()));
                    bool hitTD = ((pos.x >= r.x-p.getRectW()/2.0f+1.0f && pos.x <= r.x+p.getRectW()/2.0f+1.0f)&&CheckCollisionCircleRec(pos,rad,p.getRect()));
                    
                    if(hitTD&&!hitLR){
                        acc.y *= -1;
                        cout << "acertou os td" << endl;
                        bs->erase(bs->begin()+i);
                    }
                    else if(hitLR&&!hitTD){
                        acc.x *= -1;
                        cout << "acertou os lr" << endl;
                        bs->erase(bs->begin()+i);
                    }
                    else if(hitTD&&hitLR){
                        acc.x *= -1;
                        acc.y *= -1;
                        cout << "acertou o canto" << endl;
                        bs->erase(bs->begin()+i);
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