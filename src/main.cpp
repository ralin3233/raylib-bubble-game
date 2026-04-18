#include "raylib.h"
#include "bubble.h"

int main() {
    InitWindow(800, 450, "Raylib OOP");
    SetTargetFPS(60);

    Bubbles b(1, 10);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        b.update(GetFrameTime());
        b.draw();
        b.move();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
