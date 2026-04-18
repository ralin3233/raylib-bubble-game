#include "raylib.h"
#include "bubble.h"
#include <string>

typedef enum GameScreen { TITLE=0, GAMEPLAY, ENDING } GameScreen;

int main() {
    InitWindow(800, 450, "Raylib OOP");
    SetTargetFPS(60);
    
    GameScreen currentScreen = TITLE;
    int score = 0;
    float time = 30;
    Bubbles b(0.8, 12);
    Bubble example({50, 50},{80,80},35, MAGENTA);

    while (!WindowShouldClose()) {

        switch (currentScreen)
        {
        case TITLE:
            if (IsKeyPressed(KEY_ENTER)){
                score = 0;
                time = 30;
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
            time -= GetFrameTime();
            if (time <= 0){
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
            DrawText("BUBBLE POP GAME", 210, 120, 40, DARKBLUE);
            DrawText("Press ENTER to start", 260, 230, 20, DARKGRAY);
            
            break;
        case GAMEPLAY:
            b.draw();
            DrawText(TextFormat("Score: %05d", score), 20, 20, 30, DARKGRAY);
            DrawText(TextFormat("Time: %.0f", time), 20, 70, 30, DARKGRAY);
            break;
        case ENDING:
            b.draw();
            DrawRectangle(0, 0, 800, 450, Fade(BLACK, 0.8f)); // 半透明背景
            DrawText("GAME OVER", 280, 150, 40, WHITE);
            DrawText(TextFormat("Final Score: %d", score), 310, 220, 20, YELLOW);
            DrawText("Press ENTER back to title", 240, 300, 20, LIGHTGRAY);

            
            break;
        default:
            break;
        }
        

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
