#pragma once
#include "raylib.h"

struct Ball
{
    Ball();
    ~Ball();

    float x, y, speedX, speedY, radius;

    void Update();
    void Draw();
};
