#include "raylib.h"
#include "bubble.h"
#include <string>

int main() {
    InitWindow(800, 450, "Raylib OOP");
    SetTargetFPS(60);
    //Vector2 mouse;
    int score = 0;
    Bubbles b(1, 10);
    while (!WindowShouldClose()) {

        b.update(GetFrameTime());
        if(b.clickedCheck()){
            score++;
        };

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText(TextFormat("SCORE: %05d", score), 20, 20, 30, DARKGRAY);

        b.draw();
        b.move();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
