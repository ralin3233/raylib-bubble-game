#include "raylib.h"
#include "bubble.h"

int main() {
    InitWindow(800, 450, "Raylib OOP");
    SetTargetFPS(60);
    //Vector2 mouse;
    Bubbles b(1, 10);
    while (!WindowShouldClose()) {

        b.update(GetFrameTime());
        b.clickedCheck();

        BeginDrawing();
        ClearBackground(RAYWHITE);
        b.draw();
        b.move();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
