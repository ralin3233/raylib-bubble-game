#include "raylib.h"
#include "bubble.h"
#include <string>

typedef enum GameScreen { TITLE=0, GAMEPLAY, ENDING } GameScreen;

int main() {
    InitWindow(800, 450, "Raylib OOP");
    SetTargetFPS(60);
    
    GameScreen currentScreen = TITLE;
    int score = 0;
    Bubbles b(1, 10);
    Bubble example({50, 50},{80,80},35, MAGENTA);
    while (!WindowShouldClose()) {

        switch (currentScreen)
        {
        case TITLE:
            if (IsKeyPressed(KEY_ENTER)){
                score = 0;
                currentScreen = GAMEPLAY;
            }
            example.move();
            break;
        case GAMEPLAY:
            b.update(GetFrameTime());
            if(b.clickedCheck()){
                score++;
            };
            if (IsKeyPressed(KEY_ENTER)){
                currentScreen = ENDING;
            }
            b.move();
            break;
        case ENDING:
            if (IsKeyPressed(KEY_ENTER)){
                currentScreen = TITLE;
            }
            break;
        default:
            break;
        }


        

        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (currentScreen)
        {
        case TITLE:
            example.draw();
            DrawText("BUBBLE POP GAME", 200, 150, 40, DARKBLUE);
            DrawText("PRESS ENTER TO START", 240, 220, 20, DARKGRAY);
            
            break;
        case GAMEPLAY:
            b.draw();
            DrawText(TextFormat("SCORE: %05d", score), 20, 20, 30, DARKGRAY);
            break;
        case ENDING:
            b.draw();
            DrawRectangle(0, 0, 800, 450, Fade(BLACK, 0.8f)); // 半透明背景
            DrawText("GAME OVER", 280, 150, 40, WHITE);
            DrawText(TextFormat("FINAL SCORE: %d", score), 310, 220, 20, YELLOW);
            DrawText("PRESS ENTER BACK TO TITLE", 240, 300, 20, LIGHTGRAY);

            
            break;
        default:
            break;
        }
        

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
