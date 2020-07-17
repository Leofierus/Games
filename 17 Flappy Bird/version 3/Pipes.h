#pragma once
#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include <ctime>
#include "GameOver.h"
#include "Pipes.h"
class Pipes
{
public:
	Pipes(int PositionX, int PositionY, int PipeDistance, int PipeAbove);
	~Pipes();

	void draw(sf::RenderWindow& window);
	int OverlapTest(float FlappyBirdX, float FlappyBirdY);
	int Points(float FlappyBirdX);

	float Speed = -5;

	int Position_X = 700;
	int Position_Y = 0;
	int PipeGap;

	bool OnePointPerPipe = false;
	
	sf::Texture PipeUp, PipeDown;
	sf::Sprite PipeSpriteUp,PipeSpriteDown;

	sf::SoundBuffer Hit;
	sf::Sound HitSound;

};

