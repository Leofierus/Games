#pragma once
#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include "Pipes.h"

class GameOver
{
public:
	GameOver();
	~GameOver();

	sf::Texture Game_Over, ScoreBoard, BronzeMedal, SilverMedal, GoldMedal, PlatinumMedal;
	sf::Sprite Game_over_Sprite, ScoreBoardSprite, BronzeMedalSprite, SilverMedalSprite, GoldMedalSprite, PlatinumMedalSprite;
	void PipeCollision(sf::RenderWindow &window, bool isGameOver, int points);

	float ScoreBoardSpeed = -9;
	float ScoreBoardVelocity = 0;

	bool GameOverQueue = false;
};

