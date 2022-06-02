#include "../_build/Ball.h"

Ball::Ball()
{
    //useful variables
    x = GetScreenWidth() / 2.0f;
    y = GetScreenHeight() / 2.0f;
    radius = 5;
    speedX = 300;
    speedY = 300;
}

Ball::~Ball()
{}

void Ball::Draw()
{
    //draw the pong ball
    DrawCircle((int)x, (int)y, radius, WHITE);
}

void Ball::Update()
{
    //updates of the ball
    x += speedX * GetFrameTime();
    y += speedY * GetFrameTime();

    //bounce the ball
    if (y < 0)
    {
        y = 0;
        speedY *= -1;
    }

    if (y > GetScreenHeight())
    {
        y = GetScreenHeight();
        speedY *= -1;
    }
}