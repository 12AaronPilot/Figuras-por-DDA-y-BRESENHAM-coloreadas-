#include <iostream>
#include "raylib.h"
#include "Line.h"

int main()
{
    Line* line = new Line();
    Color bgColor = Color{ 0,0,0,255 };

    InitWindow(1200, 1000, "Swirly Circles Algorithms");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(bgColor);

        // Círculo usando DDA
        double radius = 150.0;
        double circumference = 36;
        int centerX = 400;
        int centerY = 300;
        float x2, y2;
        double angleIncrement = 2 * PI / circumference;
        float xbres = 5;
        float ybres = 5;



        //Circulo por bresenham
            line->FillCircle(880, 100, 100, GRAY);
            line->DrawCircleLinesBresenham(880, 100, 100, RED);
            line->DrawCirclelBresenham(880, 100, 100, BLUE);

        //Circulo por DDA
            line->FillCircle(880, 350, 100, GRAY);
            line->DrawCirculeDDA(880, 350, 100, RED);
            line->DrawCirculeDDShape(880, 350, 100, BLUE);


        //Triangulo por BRESENHAM
           line->FillTriangleMaxMin(300, 100, 50, 150, 300, 150, YELLOW);
           line->DrawTriangleBresenham(300, 100, 50, 150, 300, 150, PURPLE);
            
           //Triangulo por DDA
            line->FillTriangleMaxMin(400, 200, 150, 250, 400, 250, ORANGE);
            line->DrawTriangleDDA(400, 200, 150, 250, 400, 250, GREEN);

            //Cuadrado por BRESENHAM
            line->FillSquareWithTriangles(525, 525, 700, 525, 700, 700, 525, 700, DARKPURPLE);
            line->DrawRectBresenham(525, 525, 700, 525, 700, 700, 525, 700, SKYBLUE);

            //Cuadrado por DDA
            line->FillSquareWithTriangles(700, 700, 900, 700, 900, 900, 700, 900, LIGHTGRAY);
            line->DrawRectDDA(700, 700, 900, 700, 900, 900, 700, 900, MAROON);




     
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

