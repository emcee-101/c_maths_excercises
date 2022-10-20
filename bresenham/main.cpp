
// Base Code provided by Professor Sahm

#include "widget.hpp"



// -----------------------------------------------------------------------------
// Draws a line from (X1,Y1) to (X2,Y2).
// -----------------------------------------------------------------------------
void DrawLine(int _X1, int _Y1, int _X2, int _Y2)
{
    // Draws a horizontal line at the moment. 
    // Change this to draw an arbitrary line.
    for (int X = _X1; X < _X2; ++X)
    {
        DrawPixel(X, _Y1);
    }
}

// -----------------------------------------------------------------------------
// Callback which indicates that the window is drawn.
// -----------------------------------------------------------------------------
void OnDraw()
{
    // Add another DrawLine command here if you want to draw multiple lines.
    DrawLine(20, 100, 620, 100);
}

void main()
{
    OpenWindow(640, 480, "GDV Lesson 2");

    Run();

    CloseWindow();
}