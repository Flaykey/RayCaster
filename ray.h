#pragma once
#include<raylib.h>

class Rays
{
public:
    Rays(int x , int y, Vector2 dir);
    void draw();
    int x1;
    int x2;
    int y1;
    int y2;
    Vector2 dir;
};
