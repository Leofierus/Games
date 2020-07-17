#include <SFML/Graphics.hpp>
#include <iostream>
#include "Pipes.h"
#include "Points.h"


int main()
{
	sf::Vector2f velocity(sf::Vector2f(0, 0));
	sf::Vector2u windowSize(800, 700);
	sf::Vector2i NumberPosition(380, 40);
	const float gravity = 0.3;
	int groundHeight = 640;
	int FlappyPoints = 0;
	int AngleIncrease = -30;
	int AngleDownfall = 1;
	float moveSpeed = 5, jumpSpeed = 2.5;
	float Angle = 0;

	bool Once = false;
	bool OnePerPoint = false;
	bool CollisionHit = false;
	bool GameStart = false;
	bool GameOverSoundFix = false;
	bool GameOverSoundFix1 = false;
	bool SecondHitPrevent = true;

	Pipes pipe1(800, 378, 0, 830);
	Pipes pipe2(800, 378, 400, 830);

	Points numbers;

	GameOver End;




	sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "FlappyBird");
	/////////////////////////////////////////////////////////////////////////////////////////////////////////// Sprites
	sf::Texture Flappy, BackGround, Grass;
	sf::Sprite FlappyBird, BackGroundSprite, GrassSprite;
	if (!Flappy.loadFromFile("images/FlappyBird.png", sf::IntRect(0, 490, 25, 25)))
	{
	}
	if (!BackGround.loadFromFile("images/FlappyBird.png", sf::IntRect(146, 0, 144, 256)))
	{
	}
	if (!Grass.loadFromFile("images/FlappyBird.png", sf::IntRect(292, 0, 168, 56)))
	{
	}
	GrassSprite.setTexture(Grass);
	GrassSprite.setScale(5.7, 1);
	GrassSprite.setPosition(0, 670);
	BackGroundSprite.setTexture(BackGround);
	BackGroundSprite.setScale(5.6,3);
	FlappyBird.setTexture(Flappy);
	FlappyBird.setPosition(200, 300);
	FlappyBird.setScale(3, 3);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////  Audio
	sf::SoundBuffer FlappyJump, FlappyPoint, FlappyCollision;
	sf::Sound FlappyJumpSound, FlappyPointSound, FlappyCollisionSound;
	if (!FlappyJump.loadFromFile("audio/sfx_wing.wav"))
	{
	}
	if (!FlappyPoint.loadFromFile("audio/sfx_point.wav"))
	{
	}
	if (!FlappyCollision.loadFromFile("audio/sfx_hit.wav"))
	{
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FlappyJumpSound.setBuffer(FlappyJump);
	FlappyPointSound.setBuffer(FlappyPoint);
	FlappyCollisionSound.setBuffer(FlappyCollision);
	window.setFramerateLimit(120);

	std::cout << FlappyPoints << std::endl;

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		///////////////////////////////////////////////////////////////////// here we wait for the user to press Space to start the game
		while (!GameStart)
		{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			GameStart = true;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
			window.clear();
			window.draw(BackGroundSprite);
			window.draw(GrassSprite);
			window.draw(FlappyBird);
			window.display();

		}
		///////////////////////////////////////////////////////////////////// Here we got the controls for the birdy
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			velocity.x = moveSpeed;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			velocity.x = -moveSpeed;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if(!Once)
			{

				Angle = AngleIncrease;
				if (!CollisionHit)
				{
					velocity.y = 0;
					FlappyJumpSound.play();
				}
					velocity.y += -jumpSpeed * 3;
					
				Once = true;
			}
	    }
		else
		{
			velocity.x = 0;
			Once = false;
		}
		FlappyBird.move(velocity.x, velocity.y);



			FlappyBird.setRotation(Angle);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
				return main();
			}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Here we draw the scoreboard and halt all moevements when we hit the pipe
		if ((pipe1.OverlapTest(FlappyBird.getPosition().x, FlappyBird.getPosition().y)) ||
			(pipe1.OverlapTest(FlappyBird.getPosition().x, FlappyBird.getPosition().y)) ||
			(pipe2.OverlapTest(FlappyBird.getPosition().x, FlappyBird.getPosition().y)) ||
			(pipe2.OverlapTest(FlappyBird.getPosition().x, FlappyBird.getPosition().y)))
		{
			if (GameOverSoundFix)
			{
				NumberPosition.y += -9;
				if (NumberPosition.y <= 300)
				{
					NumberPosition.y = 300;
				}
			}
			else
			{
				FlappyCollisionSound.play();
				pipe1.Speed = 0;
				pipe2.Speed = 0;
				moveSpeed = 0;
				jumpSpeed = 0;
				NumberPosition.x = 545;
				NumberPosition.y = 870;
				AngleDownfall = 3;
				AngleIncrease = 60;
				GameOverSoundFix = true;
				SecondHitPrevent = false;//this boolean is used to prevent the floor collision from activating and redrawing stuff unnecesary. 
				CollisionHit = true;

			}
		}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Here we got the point system
		if (pipe1.Points(FlappyBird.getPosition().x) || pipe2.Points(FlappyBird.getPosition().x))
		{
			if (!OnePerPoint)
			{

				FlappyPoints++;
				FlappyPointSound.play();
				std::cout << FlappyPoints << std::endl;
				OnePerPoint = true;
			}
		}
		else
			OnePerPoint = false;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Here we have collision for the ground
		if (FlappyBird.getPosition().y + FlappyBird.getScale().y < groundHeight || velocity.y < 0)                                                 // We draw the scoreboard and halt all movements here
		{ 
			velocity.y += gravity;
		}
		else
		{
			if (SecondHitPrevent)//this is used so that we dont draw and stop/pause the game twice after we hit the pipe(because we fall down and hit the floor then). it becomes false at the pipe version of this
			{
				if (GameOverSoundFix1)
				{
					NumberPosition.y += -9;
					if (NumberPosition.y <= 300)
					{
						NumberPosition.y = 300;
					}
				}
				else
				{
					FlappyBird.setPosition(FlappyBird.getPosition().x, groundHeight - FlappyBird.getScale().y);
					velocity.y = 0;
					CollisionHit = true;
					FlappyCollisionSound.play();
					pipe1.Speed = 0;
					pipe2.Speed = 0;
					moveSpeed = 0;
					jumpSpeed = 0;
					NumberPosition.x = 545;
					NumberPosition.y = 870;
					AngleIncrease = 60;
					AngleDownfall = 3;
					GameOverSoundFix1 = true;
				}
			}
			else
			{
				FlappyBird.setPosition(FlappyBird.getPosition().x, groundHeight - FlappyBird.getScale().y);
				velocity.y = 0;
			}
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if(Angle < 60)
		Angle += AngleDownfall;

		window.clear();
		window.draw(BackGroundSprite);
		pipe1.draw(window);
		pipe2.draw(window);
		window.draw(GrassSprite);
		window.draw(FlappyBird);
        End.PipeCollision(window, CollisionHit, FlappyPoints); //If we collide we draw "game over" here.
		numbers.PointSystem(window, FlappyPoints, NumberPosition.x, NumberPosition.y); // 380 and 40(NumberPoisition) are the positions for the numbers on the screen while the game is in progress.
		window.display();
	}

	return 0;
}