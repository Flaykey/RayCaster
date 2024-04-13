#include<iostream>
#include"ray.h"
#include<raylib.h>

Rays::Rays(int x, int y, Vector2 dir){
    this->x1 = x;
    this->y1 = y;
    this->dir = dir; 

}

void Rays::draw()
{   
    x1 = GetMouseX();
    y1 = GetMouseY();
    DrawLine(x1,y1,x2,y2,WHITE);
}
