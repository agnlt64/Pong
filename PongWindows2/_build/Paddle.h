#pragma once
#include "raylib.h"

struct Paddle
{
    Paddle();
    ~Paddle();

    float x, y, speed, width, height;

    Rectangle GetRect();

    void Draw();
};