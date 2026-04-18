#pragma once
#include "raylib.h"
#include "raymath.h"

class Bubble{
    Vector2 position;
    Vector2 speed;
    float radius;
    Color color;

    public:
    Bubble(Vector2 pos, Vector2 spd, float r, Color c);
    void draw() const;
    void move(){
        position = Vector2Add(position, Vector2Scale(speed, GetFrameTime()));
    }
};