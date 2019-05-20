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
        float vel,rad=10.0;
        int score=0;
    public:
        ball(){}

        ball(float x, float y){
            pos.x = x;
            pos.y = y;
        }

        void setPos(float x, float y){
            pos.x=x;
            pos.y=y;

        }
        void setVel(float v){
            vel = v;
        }
        float getVel(){
            return vel;
        }
        void update(){
            pos.x = pos.x + (acc.x*vel)*GetFrameTime();
            pos.y = pos.y + (acc.y*vel)*GetFrameTime(); 
        }
        void draw(){
            DrawCircle(pos.x,pos.y,rad,BLUE);
        }
        void collision(player *p){
            
            
                Vector2 r;
                r = p->getCenter();

                    float dx = sqrt(pow(pos.x - r.x,2));
                    float dy = sqrt(pow(pos.y - r.y,2));
                    float dInsRect = sqrt(pow(r.x+p->getRectW()/2.0f,2)+pow(r.y+p->getRectH()/2.0f,2));
                    float dInsCirc = rad;

                    float dCenters =  sqrt(pow(dx,2)+pow(dy,2));

                    float dOutlines = dCenters - dInsCirc;
                    if(CheckCollisionCircleRec(pos,rad,p->getRect())){
                        if(dOutlines == dInsRect){
                            cout << "bateu canto" << endl;
                            acc.x *=-1;
                            acc.y *= -1;
                        }else if(dOutlines < dInsRect && dOutlines >= p->getRectW()/2.0f){
                                if(dy < p->getRectH()/2.0f){
                                    //cout << "bateu lateral" << endl;
                                    acc.y *= -1;
                                }else{
                                    //cout << "lados x" << endl;
                                    acc.x *=-1;
                                }
                        }else if(dOutlines < p->getRectW()/2.0f){
                            //cout << "bateu meio x" << endl;
                            acc.y *= -1;
                        }
                    }
        }
        bool collision(vector<blocks> *bs){
                //blocks bc=b;
                bool hit = false;
                for(int i=0;i< bs->size();i++){
                    //blocks p= bs->at(i);
                    blocks *p = bs->data()+i;
                    Vector2 r;
                    r = p->getCenter();

                    /*bool hitLR =((pos.y >= r.y-p->getRectH()/2.0f && pos.y <= r.y+p->getRectH()/2.0f)&&CheckCollisionCircleRec(pos,rad,p->getRect()));
                    bool hitTD = ((pos.x >= r.x-p->getRectW()/2.0f+1.0f && pos.x <= r.x+p->getRectW()/2.0f+1.0f)&&CheckCollisionCircleRec(pos,rad,p->getRect()));
                    
                    if(hitTD&&!hitLR){
                        acc.y *= -1;
                        cout << "acertou os td" << endl;
                        if(p->getLevel() == 1){
                            bs->erase(bs->begin()+i);
                            score = p->getValue();
                            hit = true;
                            continue;
                        }
                        p->setLevel(p->getLevel()-1);
                        hit= true;
                        continue;
                    }
                    else if(hitLR&&!hitTD){
                        acc.x *= -1;
                        cout << "acertou os lr" << endl;
                        if(p->getLevel() == 1){
                            bs->erase(bs->begin()+i);
                            score = p->getValue();
                            hit = true;
                            continue;
                        }
                        p->setLevel(p->getLevel()-1);
                        hit = true;
                        continue;
                    }
                    else if(hitTD&&hitLR){
                        acc.x *= -1;
                        acc.y *= -1;
                        cout << "acertou o canto" << endl;
                        if(p->getLevel() == 1){
                            bs->erase(bs->begin()+i);
                            score = p->getValue();
                            hit = true;
                            continue;
                        }
                        p->setLevel(p->getLevel()-1);
                        hit = true;
                        continue;
                    }*/
                    float dx = sqrt(pow(pos.x - r.x,2));
                    float dy = sqrt(pow(pos.y - r.y,2));
                    float dInsRect = sqrt(pow(r.x+p->getRectW()/2.0f,2)+pow(r.y+p->getRectH()/2.0f,2));
                    float dInsCirc = rad;

                    float dCenters =  sqrt(pow(dx,2)+pow(dy,2));

                    float dOutlines = dCenters - dInsCirc;
                    if(CheckCollisionCircleRec(pos,rad,p->getRect())){
                        if(dOutlines == dInsRect){
                            cout << "bateu canto" << endl;
                            acc.x *=-1;
                            acc.y *= -1;
                            bs->erase(bs->begin()+i);
                        }else if(dOutlines < dInsRect && dOutlines >= p->getRectW()/2.0f){
                                if(dy < p->getRectH()/2.0f){
                                    //cout << "bateu lateral" << endl;
                                    acc.x *= -1;
                                    bs->erase(bs->begin()+i);
                                }else{
                                    //cout << "lados x" << endl;
                                    acc.y *=-1;
                                    bs->erase(bs->begin()+i);
                                }
                        }else if(dOutlines < p->getRectW()/2.0f){
                            //cout << "bateu meio x" << endl;
                            acc.y *= -1;
                            bs->erase(bs->begin()+i);
                        }
                    }


                }
                return hit;
                
            
        }
        void collision(){
            if(pos.x>490 || pos.x < 10){
                acc.x *= -1;
            }
            if(pos.y>590 || pos.y <10){
                acc.y *= -1;
            }
        }
        int getScore(){
            return score;
        }

        
};


#endif