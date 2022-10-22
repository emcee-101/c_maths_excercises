
// Base Code provided by Professor Sahm

#include "widget.hpp"
#include <iostream>



// -----------------------------------------------------------------------------
// Draws a line from (X1,Y1) to (X2,Y2).
// -----------------------------------------------------------------------------
void DrawLine(int _X1, int _Y1, int _X2, int _Y2)
{

    // OWN CODE

    int distance_X = _X2 - _X1;
    int distance_Y = _Y2 - _Y1;

    if (distance_X < 0) distance_X = -distance_X;
    if (distance_Y < 0) distance_Y = -distance_Y;

    // decide if x or y is growing faster
    // only x implemented at the moment
    if (distance_X < distance_Y) {

        int cur_Y = 0;
        double cur_err = distance_X / 2.0f;


        // draw initial Point
        DrawPixel(_X1, _Y1);
    

        for (int cur_X = 1; cur_X < distance_X; ++cur_X)
        {
            
            cur_err -=  distance_Y;
            

            // decide wether cur_Y can be elevated or not
            if (cur_err < 0) {

                cur_Y += 1;
                cur_err += distance_X;

            };

            //  Debug Output:
            //      std::cout << "Point X= " << cur_X << ", Y= " << cur_Y << "\n";

            DrawPixel(cur_X+_X1, cur_Y+_Y1);

        }
    };

}

// -----------------------------------------------------------------------------
// Callback which indicates that the window is drawn.
// -----------------------------------------------------------------------------
void OnDraw()
{
    // Add another DrawLine command here if you want to draw multiple lines.
    //DrawLine(20, 100, 620, 100);
    
    // Line to leverage the Bresenham Algorithm
    DrawLine(20, 100, 620, 200);
}

void main()
{
    OpenWindow(640, 480, "GDV Lesson 2");

    Run();

    CloseWindow();
}