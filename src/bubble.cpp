#include "bubble.h"

Bubble::Bubble(Vector2 pos, Vector2 spd, float r, Color c): position(pos), speed(spd), radius(r), color(c){}

void Bubble::draw() const {
        DrawCircleV(position, radius, color);
    }