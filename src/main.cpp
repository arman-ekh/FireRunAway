#include "raylib.h"


int main(){
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "My Raylib Project");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground((Color){110,65,125});

        DrawText("Hello Raylib!", 280, 280, 30, WHITE);

        EndDrawing();
    }

    CloseWindow();
}