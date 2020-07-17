#include "GameOver.h"
#include "Pipes.h"
#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>



GameOver::GameOver()
{
	if (!Game_Over.loadFromFile("images/FlappyBird.png", sf::IntRect(395, 59, 100, 21)))
	{
	}
	Game_over_Sprite.setTexture(Game_Over);
	Game_over_Sprite.setScale(3, 3);
	Game_over_Sprite.setPosition(250, 710);

	if (!ScoreBoard.loadFromFile("images/FlappyBird.png", sf::IntRect(3, 259, 113, 57)))
	{
	}
	ScoreBoardSprite.setTexture(ScoreBoard);
	ScoreBoardSprite.setScale(4, 4);
	ScoreBoardSprite.setPosition(165, 800);

	if (!BronzeMedal.loadFromFile("images/FlappyBird.png", sf::IntRect(112, 477, 22, 22)))
	{
	}
	BronzeMedalSprite.setTexture(BronzeMedal);
	BronzeMedalSprite.setScale(4, 4);
	BronzeMedalSprite.setPosition(217, 886);
	if (!SilverMedal.loadFromFile("images/FlappyBird.png", sf::IntRect(112, 453, 22, 22)))
	{
	}
	SilverMedalSprite.setTexture(SilverMedal);
	SilverMedalSprite.setScale(4, 4);
	SilverMedalSprite.setPosition(217, 886);
	if (!GoldMedal.loadFromFile("images/FlappyBird.png", sf::IntRect(121, 282, 22, 22)))
	{
	}
	GoldMedalSprite.setTexture(GoldMedal);
	GoldMedalSprite.setScale(4, 4);
	GoldMedalSprite.setPosition(217, 886);
	if (!PlatinumMedal.loadFromFile("images/FlappyBird.png", sf::IntRect(121, 258, 22, 22)))
	{
	}
	PlatinumMedalSprite.setTexture(PlatinumMedal);
	PlatinumMedalSprite.setScale(4, 4);
	PlatinumMedalSprite.setPosition(217, 886);
}


GameOver::~GameOver()
{
}

void GameOver::PipeCollision(sf::RenderWindow &window, bool isGameOver, int points)
{
	if (isGameOver)
	{
		if (ScoreBoardSprite.getPosition().y <= 230)
		{
			ScoreBoardSpeed = 0;
			//ScoreBoardVelocity = 0;
		}

		ScoreBoardSprite.move(0, ScoreBoardSpeed);
		Game_over_Sprite.move(0, ScoreBoardSpeed);
		window.draw(Game_over_Sprite);
		window.draw(ScoreBoardSprite);
		if (points >= 10 && points <= 19)
		{
			window.draw(BronzeMedalSprite);
			BronzeMedalSprite.move(0, ScoreBoardSpeed);
		}
		else if (points >= 20 && points < 30)
		{
			window.draw(SilverMedalSprite);
			SilverMedalSprite.move(0, ScoreBoardSpeed);
		}
		else if (points >= 30 && points < 40)
		{
			window.draw(GoldMedalSprite);
			GoldMedalSprite.move(0, ScoreBoardSpeed);
		}
		else if (points >= 40 && points)
		{
			window.draw(PlatinumMedalSprite);
			PlatinumMedalSprite.move(0, ScoreBoardSpeed);
		}
	}

}
