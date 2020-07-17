#pragma once
#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
class Points
{
public:
	Points();
	~Points();

	void PointSystem(sf::RenderWindow& window, int FlappyPoints, int PointPositionX, int PointPositionY);

	sf::Texture ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE;
	sf::Sprite sZERO, sONE, sTWO, sTHREE, sFOUR, sFIVE, sSIX, sSEVEN, sEIGHT, sNINE, sONEDouble, sTWODouble, sTHREEDouble;
};

