#include "enviroment/Floor.h"
#include "raylib.h"
#include "visualization/renderer.h"



int main(){
    const int screenWidth = 1080;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "My Raylib Project");

    SetTargetFPS(60);
    Renderer renderer = Renderer();
    Floor floor = Floor(1, 10, 10);

    renderer.set_floor_ptr(&floor);



    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(WHITE);
        renderer.draw_floor();


        EndDrawing();
    }
    CloseWindow();
}