#include "../_build/Game.h"

int main(int argc, char** argv)
{
    //create a window
    InitWindow(800, 600, "Pong");
    //set the differents flags, here fps which will stay close to the monitor refresh rate
    SetWindowState(FLAG_VSYNC_HINT);

    Game game;

    //main loop
    while (! WindowShouldClose())
    {
        //draw in the window
        BeginDrawing();
        //change the background color
        ClearBackground(BLACK);

        game.Draw();
        game.HandleInput();
        game.DetectCollision();
        game.Update();
        game.CheckWinner();
        game.DisplayWinner();
        game.Reset();

        //display the fps
        DrawFPS(10, 10);
        //stop drawing
        EndDrawing();
    }

    //destroy window
    CloseWindow();

    return 0;
}