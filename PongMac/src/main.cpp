#include "raylib.h"

struct Ball
{
    float x, y, speedX, speedY, radius;
    //draw circle
    void Draw()
    {
        //draw the pong ball
        DrawCircle((int)x, (int)y, radius, WHITE);
    }
};

struct Paddle
{
    float x, y, speed, width, height;

    Rectangle GetRect()
    {
        return Rectangle{x - width / 2, y - height / 2, 10, 100};
    }

    void Draw()
    {
        DrawRectangleRec(GetRect(), WHITE);
    }
};

int main(int argc, char** argv)
{
    //create a window
    InitWindow(800, 600, "Pong");
    //set the differents flags, here fps which will stay close to the monitor refresh rate
    SetWindowState(FLAG_VSYNC_HINT);

    Ball ball;
    Paddle leftPaddle;
    Paddle rightPaddle;

    //useful variables
    ball.x = GetScreenWidth() / 2.0f;
    ball.y = GetScreenHeight() / 2.0f;
    ball.radius = 5;
    ball.speedX = 300;
    ball.speedY = 300;

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

    const char* winnerText = nullptr;
    const char* restartText = "Press Space to restart";

    //main loop
    while(not WindowShouldClose())
    {
        //updates of the ball
        ball.x += ball.speedX * GetFrameTime();
        ball.y += ball.speedY* GetFrameTime();

        //bounce the ball
        if(ball.y < 0)
        {
            ball.y = 0;
            ball.speedY *= -1;
        }

        if(ball.y > GetScreenHeight())
        {
            ball.y = GetScreenHeight();
            ball.speedY *= -1;
        }
        
        //user input for left paddle
        /*KEYBOARD IS IN QWERTY BY DEFAULT SO CHOOSE INPUTS IN QWERTY IN THE CODE WILL ALLOW YOU TO USE YOUR OWN KEYBOARD*/
        if(IsKeyDown(KEY_W))
        {
            //W stands for Z in azerty
            leftPaddle.y -= leftPaddle.speed * GetFrameTime();
        }
        if(IsKeyDown(KEY_S))
        {
            leftPaddle.y += leftPaddle.speed * GetFrameTime();
        }

        //user input for right paddle
        if(IsKeyDown(KEY_UP))
        {
            rightPaddle.y -= rightPaddle.speed * GetFrameTime();
        }

        if(IsKeyDown(KEY_DOWN))
        {
            rightPaddle.y += rightPaddle.speed * GetFrameTime();
        }

        //collision detection
        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, leftPaddle.GetRect()))
        {
            if(ball.speedX < 0)
            {
                //bounce the ball against the left paddle
                ball.speedX *= -1.1f;
                ball.speedY = (ball.y - leftPaddle.y) / (leftPaddle.height / 2) * ball.speedX;
            }
        }

        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, rightPaddle.GetRect()))
        {
            if(ball.speedX > 0)
            {
                //bounce the ball against the right paddle
                ball.speedX *= -1.1f;
                ball.speedY = (ball.y - rightPaddle.y) / (rightPaddle.height / 2) * -ball.speedX;
            }
        }

        //check the winner
        if(ball.x < 0)
        {
            winnerText = "Right player wins !";
        }

        if(ball.x > GetScreenWidth())
        {
            winnerText = "Left player wins !";
        }

        //key to restart and reset the game
        if(winnerText and IsKeyPressed(KEY_SPACE))
        {
            ball.x = GetScreenWidth() / 2;
            ball.y = GetScreenHeight() /2;
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

        //draw in the window
        BeginDrawing();
        //change the background color
        ClearBackground(BLACK);

        //draw the ball
        ball.Draw();

        //draw the rectangles
        leftPaddle.Draw();
        rightPaddle.Draw();

        //display the winner
        if(winnerText)
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

        //display the fps
        DrawFPS(10, 10);

        //stop drawing
        EndDrawing();
    }

    //destroy window
    CloseWindow();

    return 0;
}