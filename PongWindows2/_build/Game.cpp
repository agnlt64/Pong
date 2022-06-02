#include "../_build/Game.h"

Game::Game()
{
    //other useful variables
    leftPaddle.x = 50;
    leftPaddle.y = GetScreenHeight() / 2;
    leftPaddle.width = 10;
    leftPaddle.height = 100;
    leftPaddle.speed = 500;

    rightPaddle.x = GetScreenWidth() - 50;
    rightPaddle.y = GetScreenHeight() / 2;
    rightPaddle.width = 10;
    rightPaddle.height = 100;
    rightPaddle.speed = 500;
}

Game::~Game()
{}

void Game::Draw()
{
    ball.Draw();
    rightPaddle.Draw();
    leftPaddle.Draw();
}

void Game::Update()
{
    ball.Update();
}

void Game::HandleInput()
{
    //user input for left paddle
    /*KEYBOARD IS IN QWERTY BY DEFAULT SO CHOOSE INPUTS IN QWERTY IN THE CODE WILL ALLOW YOU TO USE YOUR OWN KEYBOARD*/
    if (IsKeyDown(KEY_W))
    {
        //W stands for Z in azerty
        leftPaddle.y -= leftPaddle.speed * GetFrameTime();
    }
    if (IsKeyDown(KEY_S))
    {
        leftPaddle.y += leftPaddle.speed * GetFrameTime();
    }

    //user input for right paddle
    if (IsKeyDown(KEY_UP))
    {
        rightPaddle.y -= rightPaddle.speed * GetFrameTime();
    }

    if (IsKeyDown(KEY_DOWN))
    {
        rightPaddle.y += rightPaddle.speed * GetFrameTime();
    }
}

void Game::DetectCollision()
{
    //collision detection
    if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, leftPaddle.GetRect()))
    {
        if (ball.speedX < 0)
        {
            //bounce the ball against the left paddle
            ball.speedX *= -1.1f;
            ball.speedY = (ball.y - leftPaddle.y) / (leftPaddle.height / 2) * ball.speedX;
        }
    }

    if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, rightPaddle.GetRect()))
    {
        if (ball.speedX > 0)
        {
            //bounce the ball against the right paddle
            ball.speedX *= -1.1f;
            ball.speedY = (ball.y - rightPaddle.y) / (rightPaddle.height / 2) * -ball.speedX;
        }
    }
}

void Game::CheckWinner()
{
    //check the winner
    if (ball.x < 0)
    {
        winnerText = "Right player wins !";
    }

    if (ball.x > GetScreenWidth())
    {
        winnerText = "Left player wins !";
    }
}

void Game::Reset()
{
    //key to restart and reset the game
    if (winnerText && IsKeyPressed(KEY_SPACE))
    {
        ball.x = GetScreenWidth() / 2;
        ball.y = GetScreenHeight() / 2;
        ball.speedX = 300;
        ball.speedY = 300;
        winnerText = nullptr;

        leftPaddle.x = 50;
        leftPaddle.y = GetScreenHeight() / 2;
        leftPaddle.speed = 500;

        rightPaddle.x = GetScreenWidth() - 50;
        rightPaddle.y = GetScreenHeight() / 2;
        rightPaddle.speed = 500;
    }
}

void Game::DisplayWinner()
{
    //display the winner
    if (winnerText)
    {
        int winnerTextWidth = MeasureText(winnerText, 60);
        int winnerTextX = GetScreenWidth() / 2 - winnerTextWidth / 2;
        int winnerTextY = GetScreenHeight() / 2 - 20;
        DrawText(winnerText, winnerTextX, winnerTextY, 60, BLUE);

        //display the restart text
        int restartTextWidth = MeasureText(restartText, 30);
        int restartTextX = GetScreenWidth() / 3 - restartTextWidth / 6;
        int restartTextY = GetScreenHeight() / 3;
        DrawText(restartText, restartTextX, restartTextY, 30, BLUE);
    }
}