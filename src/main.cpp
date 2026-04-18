#include "raylib.h"
#include "bubble.h"

int main() {
    InitWindow(800, 450, "Raylib OOP");
    SetTargetFPS(60);

    Bubble b({400, 225}, {300, 200}, 20, MAROON);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        b.draw();
        b.move();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
