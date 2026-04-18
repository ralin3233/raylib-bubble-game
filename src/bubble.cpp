#include "bubble.h"
#include <cmath>
//#include <vector>
Bubble::Bubble(Vector2 pos, Vector2 spd, float r, Color c): position(pos), speed(spd), radius(r), color(c){}

void Bubble::draw() const {
        DrawCircleV(position, radius, color);
    }

void Bubble::move(){
        position = Vector2Add(position, Vector2Scale(speed, GetFrameTime()));

        //除了方向取反，推回邊界避免卡牆
        if(position.x + radius >= GetScreenWidth()){
            position.x = GetScreenWidth() - radius;
            speed.x *= -1;
        }
        if(position.x -radius <= 0){
            position.x = radius;
            speed.x *= -1;
        }
        if(position.y + radius >= GetScreenHeight()){
            position.y = GetScreenHeight() - radius;
            speed.y *= -1;
        }
        if(position.y -radius <= 0){
            position.y = radius;
            speed.y *= -1;
        }
    }

void Bubbles::draw() const {
        for(auto &bubble : bubbleList){
            bubble.draw();
        }
    }

void Bubbles::move(){
        for(auto &bubble : bubbleList){
            bubble.move();
        }

        // 2. 處理泡泡間的碰撞 (雙迴圈組合檢測)
        for (size_t i = 0; i < bubbleList.size(); i++) {
            for (size_t j = i + 1; j < bubbleList.size(); j++) {
                if (CheckCollisionCircles(bubbleList[i].position, bubbleList[i].radius, bubbleList[j].position, bubbleList[j].radius)) {
                    
                    // --- 物理反彈計算 ---
                    // 1. 計算法向量 (Normal) 與 距離 (Distance)
                    Vector2 normal = Vector2Subtract(bubbleList[j].position, bubbleList[i].position);
                    float distance = Vector2Length(normal);
                    
                    if (distance == 0) continue; // 防止除以零
                    normal = Vector2Scale(normal, 1.0f / distance); // 單位化

                    // 2. 相對速度在法向上的投影 (Dot Product)
                    Vector2 relativeVel = Vector2Subtract(bubbleList[i].speed, bubbleList[j].speed);
                    float speedUponNormal = Vector2DotProduct(relativeVel, normal);

                    // 3. 只有當兩者正趨於靠近時才處理碰撞（防止卡球）
                    if (speedUponNormal > 0) {
                        float rSquare_i = bubbleList[i].radius*bubbleList[i].radius;
                        float rSquare_j = bubbleList[j].radius*bubbleList[j].radius;
                        float impulse = speedUponNormal*2.0f/(rSquare_i+rSquare_j); // 共用衝量係數
                        
                        bubbleList[i].speed = Vector2Subtract(bubbleList[i].speed, Vector2Scale(normal, impulse*rSquare_j));
                        bubbleList[j].speed = Vector2Add(bubbleList[j].speed, Vector2Scale(normal, impulse*rSquare_i));
                    }
                    
                    // 4. 修正重疊 (Position Correction) - 防止泡泡黏在一起
                    float overlap = (bubbleList[i].radius + bubbleList[j].radius) - distance;
                    Vector2 separation = Vector2Scale(normal, overlap * 0.5f);
                    bubbleList[i].position = Vector2Subtract(bubbleList[i].position, separation);
                    bubbleList[j].position = Vector2Add(bubbleList[j].position, separation);
                }
            }
        }
    }


void Bubbles::spawn() {
        float multiplier = (GetRandomValue(0,1)== 0)?-1.0f:1.0f;
        bubbleList.push_back({
            {(float)GetRandomValue(50, 750), (float)GetRandomValue(50, 400)},
            {multiplier*(float)GetRandomValue(20, 150), multiplier*(float)GetRandomValue(20, 150)},
            (float)GetRandomValue(25, 50),
            MAROON
        });
    }

void Bubbles::update(float deltaTime) {
        if (bubbleList.size() < maxBubbles) {
            spawnTimer += deltaTime;
            if (spawnTimer >= spawnInterval) {
                spawn();
                spawnTimer = 0.0f;
            }
        }
    }
bool Bubbles::clickedCheck(){
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            Vector2 mouse = GetMousePosition();
            for(int i = bubbleList.size()-1; i >=0 ; i--){
                if (CheckCollisionPointCircle(mouse, bubbleList[i].position, bubbleList[i].radius)) {
                    bubbleList.erase(bubbleList.begin() + i);
                    return true; // 點到一顆就收工，避免穿透點擊
                }
            }
        }
    return false;
}