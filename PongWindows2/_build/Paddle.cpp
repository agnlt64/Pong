#include "../_build/Paddle.h"
#include "raylib.h"

Paddle::Paddle()
{
    x = 0;
    y = 0;
    width = 10;
    height = 100;
    speed = 500;
}

Paddle::~Paddle()
{}

Rectangle Paddle::GetRect()
{
    return Rectangle{ x - width / 2, y - height / 2, 10, 100 };
}

void Paddle::Draw()
{
    DrawRectangleRec(GetRect(), WHITE);
}