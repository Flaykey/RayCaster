#pragma once
#include"ray.h"
#include"line.h"
#include<vector>
class Particle
{
public:
    Particle();
    int x;
    int y;
    void draw(std::vector<Line> line);
    std::vector<Rays> rays;

};

