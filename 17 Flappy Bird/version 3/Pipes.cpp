#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Pipes.h"
#include "GameOver.h"


Pipes::Pipes(int PositionX, int PositionY, int PipeDistance, int PipeAbove)
{
	std::cout << "hello!" << std::endl;
	if (!PipeUp.loadFromFile("images/FlappyBird.png", sf::IntRect(84, 323, 26, 160)))
	{
	}
	if (!PipeDown.loadFromFile("images/FlappyBird.png", sf::IntRect(56, 323, 26, 160)))
	{
	}
	PipeSpriteUp.setTexture(PipeUp);
	PipeSpriteUp.setScale(4,4);
	PipeSpriteDown.setTexture(PipeDown);
	PipeSpriteDown.setScale(4, 4);

	PipeSpriteUp.setPosition(PositionX + PipeDistance, PositionY*1.4 );
	PipeSpriteDown.setPosition(PositionX + PipeDistance, PositionY - PipeAbove + 160);

	PipeGap = PipeAbove;
}


Pipes::~Pipes()
{

}

void Pipes::draw(sf::RenderWindow &window)
{
	//srand((unsigned)time(NULL));
	
	PipeSpriteUp.move(Speed, 0);
	PipeSpriteDown.move(Speed, 0);
	if (PipeSpriteUp.getPosition().x <= -100 && PipeSpriteDown.getPosition().x <= -100)
	{
		int Up = rand() % (600 + 1 - 300) + 300;
		int Down = Up - PipeGap;

		PipeSpriteUp.setPosition(800, Up);
		PipeSpriteDown.setPosition(800, Down);
	}

	window.draw(PipeSpriteUp);
	window.draw(PipeSpriteDown);

    
}

int Pipes::OverlapTest(float FlappyBirdX, float FlappyBirdY)
{
	const int left_box0 = FlappyBirdX;
	const int right_box0 = FlappyBirdX + 17 * 3;
	const int top_box0 = FlappyBirdY;
	const int bottom_box0 = FlappyBirdY + 12 * 3;

	const int left_box1 = PipeSpriteUp.getPosition().x;
	const int right_box1 = PipeSpriteUp.getPosition().x + 26 * 4;
	const int top_box1 = PipeSpriteUp.getPosition().y;
	const int bottom_box1 = PipeSpriteUp.getPosition().y + 160 * 4;

	const int left_box2 = PipeSpriteDown.getPosition().x;
	const int right_box2 = PipeSpriteDown.getPosition().x + 26 * 4;
	const int top_box2 = PipeSpriteDown.getPosition().y;
	const int bottom_box2 = PipeSpriteDown.getPosition().y + 160 * 4;

		return ((right_box0 >= left_box1 && left_box0 <= right_box1 && top_box0 <= bottom_box1 && bottom_box0 >= top_box1) || (right_box0 >= left_box2 && left_box0 <= right_box2 && top_box0 <= bottom_box2 && bottom_box0 >= top_box2));

}
int Pipes::Points(float FlappyBirdX)
{
	int left_box0 = FlappyBirdX;
	int right_box0 = FlappyBirdX + 17 * 2;

	int left_box1 = PipeSpriteDown.getPosition().x + 25;
	int right_box1 = PipeSpriteDown.getPosition().x + 26;

	int left_box2 = PipeSpriteUp.getPosition().x + 29;
	int right_box2 = PipeSpriteUp.getPosition().x + 30;

	return ((right_box0 >= left_box1 && left_box0 <= right_box1) || (right_box0 >= left_box2 && left_box0 <= right_box2));

}


