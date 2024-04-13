#include<raylib.h>
#include<ray.h>
#include<math.h>
#include"particle.h"
#include"line.h"
#include<vector>

Particle::Particle(){
    x = GetMouseX();
    y = GetMouseY();
    for(int i = 0 ; i<= 1000; i++){
        float dx = cos(i);
        float dy = sin(i);
        Vector2 dir{dx,dy};
        Rays r = Rays(x,y,dir);
        rays.push_back(r);
    }
}

void Particle::draw(std::vector<Line> line){
    int dist;
    for(int i = 0; i <= 1000; i++){
        float r = INFINITY;
        
        for(int j = 0; j< (int)line.size(); j++){ 
    float v1x = rays.at(i).x1 - line[j].x1;
    float v1y = rays.at(i).y1 - line[j].y1;
    float v2x = line[j].x2 - line[j].x1;
    float v2y = line[j].y2 - line[j].y1;
    float v3x = -rays.at(i).dir.y;
    float v3y = rays.at(i).dir.x;


    float den = v2x*v3x + v2y*v3y;
    //if (den == 0) continue;
    float t1 = (v2x*v1y - v2y*v1x)/den;
    float t2 = (v1x*v3x + v1y*v3y)/den;

    if(t1 > 0 && t2 >=0 && t2<=1){

    rays.at(i).x2 =line[j].x1 + (line[j].x2-line[j].x1)*t2;
    rays.at(i).y2 = line[j].y1 + (line[j].y2-line[j].y1)*t2;

    dist = sqrt((rays[i].x2-rays[i].x1) * (rays[i].x2-rays[i].x1) +(rays[i].y2-rays[i].y1)*(rays[i].y2-rays[i].y1));
    if (r>dist){
        r = dist;
    }
    }
    else{
    rays.at(i).x2 = rays.at(i).x1 + rays.at(i).dir.x;
    rays.at(i).y2 = rays.at(i).y1 + rays.at(i).dir.y;

    }

        }
    if(r != INFINITY){
    rays[i].x2 = rays[i].x1 + rays[i].dir.x*r;
    rays[i].y2 = rays[i].y1 + rays[i].dir.y*r;
    }
    rays.at(i).draw();
    }
    
}