#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <unistd.h>

#define ScreenWidth 900
#define ScreenHeight 600

// wtf this looks awesome
int main ()
{
    Vector2 Dot1start =  {300.0f, 100.0f};
    Vector2 Dot1end =  {300.0f, 150.0f};
    Vector2 Dot2start =  {400.0f, 100.0f};
    Vector2 Dot2end =  {400.0f, 150.0f};
    Vector2 Dot3start =  {500.0f, 100.0f};
    Vector2 Dot3end =  {500.0f, 150.0f};

    InitWindow(ScreenWidth, ScreenHeight, "test");
    SetTargetFPS(10);
    while (!WindowShouldClose())
    {
        int i = 0;

        BeginDrawing();
            ClearBackground(RAYWHITE);
        EndDrawing();
        WaitTime(1);
        BeginDrawing();
            DrawLineEx(Dot1start, Dot1end, 50, LIGHTGRAY);
        EndDrawing();
        WaitTime(1);
        BeginDrawing();
            DrawLineEx(Dot2start, Dot2end, 50, LIGHTGRAY);
        EndDrawing();
        WaitTime(1);
        BeginDrawing();
            DrawLineEx(Dot3start, Dot3end, 50, LIGHTGRAY);
        EndDrawing();
        WaitTime(1);
    }
    CloseWindow();

    return 0;
}
