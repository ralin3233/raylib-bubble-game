#pragma once
#include "raylib.h"
#include "raymath.h"
#include <vector>
class Bubble{
    friend class Bubbles;
    Vector2 position;
    Vector2 speed;
    float radius;
    Color color;

    public:
    Bubble(Vector2 pos, Vector2 spd, float r, Color c);
    void draw() const;
    void move();
};

class Bubbles{
    std::vector<Bubble> bubbleList;
    float spawnTimer;
    float spawnInterval;
    int maxBubbles;

    void spawn();

    public:
    
    Bubbles(float interval, int max) : spawnTimer(0.0f), spawnInterval(interval), maxBubbles(max) {}
    void draw() const;
    /*讓泡泡動起來*/ 
    void move();
    /*生成泡泡*/
    void update(float);

};