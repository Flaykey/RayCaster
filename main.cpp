#include <raylib.h>
#include"particle.h"
#include"line.h"
#include<vector>

int main () {
    const int width = 1000;
    const int height = 700;
    InitWindow(width,height,"RayCaster");
    Particle p = Particle();
    std::vector<Line> lines;

    Line l = Line{0,0,0,height};
    lines.push_back(l);

    l = Line{0,0,width,0};
    lines.push_back(l);

    l = Line{width,0,width,height};
    lines.push_back(l);

    l = Line{0,height,width,height};
    lines.push_back(l);

    for(int i = 1; i<=10 ; i++){
        int x1 = GetRandomValue(0,width);
        int x2 = GetRandomValue(0,height);
        int y1 = GetRandomValue(0,width);
        int y2 = GetRandomValue(0,height);
        Line line = Line{x1,y1,x2,y2};
        lines.push_back( line);
    }

    
    SetTargetFPS(60);
    while(!WindowShouldClose()){

        BeginDrawing();
        ClearBackground(BLACK);
        for (int i = 0 ; i< (int)lines.size(); i++)
        {
        lines[i].draw();
        }
        p.draw(lines);


        EndDrawing();
    }

    CloseWindow();
    return 0;
}