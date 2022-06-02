#pragma once
#include "Ball.h"
#include "Paddle.h"

struct Game
{
	Game();
	~Game();

	void Draw();
	void Update();
	void DetectCollision();
	void CheckWinner();
	void Reset();
	void DisplayWinner();
	void HandleInput();

	const char* winnerText = nullptr;
	const char* restartText = "Press Space to restart";

    Ball ball;
    Paddle leftPaddle;
    Paddle rightPaddle;

};