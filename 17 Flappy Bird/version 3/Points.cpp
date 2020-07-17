#include "Points.h"



Points::Points()
{
	if (!ZERO.loadFromFile("images/FlappyBird.png", sf::IntRect(496, 60, 12, 18)))
	{
	}
	if (!ONE.loadFromFile("images/FlappyBird.png", sf::IntRect(136, 455, 8, 18)))
	{
	}
	if (!TWO.loadFromFile("images/FlappyBird.png", sf::IntRect(292, 160, 12, 18)))
	{
	}
	if (!THREE.loadFromFile("images/FlappyBird.png", sf::IntRect(306, 160, 12, 18)))
	{
	}
	if (!FOUR.loadFromFile("images/FlappyBird.png", sf::IntRect(320, 160, 12, 18)))
	{
	}
	if (!FIVE.loadFromFile("images/FlappyBird.png", sf::IntRect(334, 160, 12, 18)))
	{
	}
	if (!SIX.loadFromFile("images/FlappyBird.png", sf::IntRect(292, 184, 12, 18)))
	{
	}
	if (!SEVEN.loadFromFile("images/FlappyBird.png", sf::IntRect(306, 184, 12, 18)))
	{
	}
	if (!EIGHT.loadFromFile("images/FlappyBird.png", sf::IntRect(320, 184, 12, 18)))
	{
	}
	if (!NINE.loadFromFile("images/FlappyBird.png", sf::IntRect(334, 184, 12, 18)))
	{
	}

	sZERO.setTexture(ZERO);
	sONE.setTexture(ONE);
	sTWO.setTexture(TWO);
	sTHREE.setTexture(THREE);
	sFOUR.setTexture(FOUR);
	sFIVE.setTexture(FIVE);
	sSIX.setTexture(SIX);
	sSEVEN.setTexture(SEVEN);
	sEIGHT.setTexture(EIGHT);
	sNINE.setTexture(NINE);

	sONEDouble.setTexture(ONE);
	sTWODouble.setTexture(TWO);
	sTHREEDouble.setTexture(THREE);

	sONEDouble.setScale(2, 2);
	sTWODouble.setScale(2, 2);
	sTHREEDouble.setScale(2, 2);

	sZERO.setScale(2, 2);
	sONE.setScale(2, 2);
	sTWO.setScale(2, 2);
	sTHREE.setScale(2, 2);
	sFOUR.setScale(2, 2);
	sFIVE.setScale(2, 2);
	sSIX.setScale(2, 2);
	sSEVEN.setScale(2, 2);
	sEIGHT.setScale(2, 2);
	sNINE.setScale(2, 2);
}


Points::~Points()
{
}

void Points::PointSystem(sf::RenderWindow& window, int FlappPointPositionYPoints, int PointPositionX, int PointPositionY)
{
	if (FlappPointPositionYPoints < 10)
	{
		sZERO.setPosition(PointPositionX, PointPositionY);
		sONE.setPosition(PointPositionX, PointPositionY);
		sTWO.setPosition(PointPositionX, PointPositionY);
		sTHREE.setPosition(PointPositionX, PointPositionY);
		sFOUR.setPosition(PointPositionX, PointPositionY);
		sFIVE.setPosition(PointPositionX, PointPositionY);
		sSIX.setPosition(PointPositionX, PointPositionY);
		sSEVEN.setPosition(PointPositionX, PointPositionY);
		sEIGHT.setPosition(PointPositionX, PointPositionY);
		sNINE.setPosition(PointPositionX, PointPositionY);
		switch (FlappPointPositionYPoints)
		{
		case 0:
			window.draw(sZERO);
			break;
		case 1:
			window.draw(sONE);
			break;
		case 2:
			window.draw(sTWO);
			break;
		case 3:
			window.draw(sTHREE);
			break;
		case 4:
			window.draw(sFOUR);
			break;
		case 5:
			window.draw(sFIVE);
			break;
		case 6:
			window.draw(sSIX);
			break;
		case 7:
			window.draw(sSEVEN);
			break;
		case 8:
			window.draw(sEIGHT);
			break;
		case 9:
			window.draw(sNINE);
			break;
		}
	}
	if (FlappPointPositionYPoints < 20)
	{
		sONEDouble.setPosition(PointPositionX - 20, PointPositionY);

		sZERO.setPosition(PointPositionX, PointPositionY);
		sONE.setPosition(PointPositionX, PointPositionY);
		sTWO.setPosition(PointPositionX, PointPositionY);
		sTHREE.setPosition(PointPositionX, PointPositionY);
		sFOUR.setPosition(PointPositionX, PointPositionY);
		sFIVE.setPosition(PointPositionX, PointPositionY);
		sSIX.setPosition(PointPositionX, PointPositionY);
		sSEVEN.setPosition(PointPositionX, PointPositionY);
		sEIGHT.setPosition(PointPositionX, PointPositionY);
		sNINE.setPosition(PointPositionX, PointPositionY);
		switch (FlappPointPositionYPoints)
		{
		case 10:
			window.draw(sONEDouble);
			window.draw(sZERO);
			break;
		case 11:
			window.draw(sONEDouble);
			window.draw(sONE);
			break;
		case 12:
			window.draw(sONEDouble);
			window.draw(sTWO);
			break;
		case 13:
			window.draw(sONEDouble);
			window.draw(sTHREE);
			break;
		case 14:
			window.draw(sONEDouble);
			window.draw(sFOUR);
			break;
		case 15:
			window.draw(sONEDouble);
			window.draw(sFIVE);
			break;
		case 16:
			window.draw(sONEDouble);
			window.draw(sSIX);
			break;
		case 17:
			window.draw(sONEDouble);
			window.draw(sSEVEN);
			break;
		case 18:
			window.draw(sONEDouble);
			window.draw(sEIGHT);
			break;
		case 19:
			window.draw(sONEDouble);
			window.draw(sNINE);
			break;
		}
	}
	if (FlappPointPositionYPoints < 30)
	{
		sTWODouble.setPosition(PointPositionX - 20, PointPositionY);

		sZERO.setPosition(PointPositionX, PointPositionY);
		sONE.setPosition(PointPositionX, PointPositionY);
		sTWO.setPosition(PointPositionX, PointPositionY);
		sTHREE.setPosition(PointPositionX, PointPositionY);
		sFOUR.setPosition(PointPositionX, PointPositionY);
		sFIVE.setPosition(PointPositionX, PointPositionY);
		sSIX.setPosition(PointPositionX, PointPositionY);
		sSEVEN.setPosition(PointPositionX, PointPositionY);
		sEIGHT.setPosition(PointPositionX, PointPositionY);
		sNINE.setPosition(PointPositionX, PointPositionY);
		switch (FlappPointPositionYPoints)
		{
		case 20:
			window.draw(sTWODouble);
			window.draw(sZERO);
			break;
		case 21:
			window.draw(sTWODouble);
			window.draw(sONE);
			break;
		case 22:
			window.draw(sTWODouble);
			window.draw(sTWO);
			break;
		case 23:
			window.draw(sTWODouble);
			window.draw(sTHREE);
			break;
		case 24:
			window.draw(sTWODouble);
			window.draw(sFOUR);
			break;
		case 25:
			window.draw(sTWODouble);
			window.draw(sFIVE);
			break;
		case 26:
			window.draw(sTWODouble);
			window.draw(sSIX);
			break;
		case 27:
			window.draw(sTWODouble);
			window.draw(sSEVEN);
			break;
		case 28:
			window.draw(sTWODouble);
			window.draw(sEIGHT);
			break;
		case 29:
			window.draw(sTWODouble);
			window.draw(sNINE);
			break;
		}
	}
	if (FlappPointPositionYPoints < PointPositionY)
	{
		sTHREEDouble.setPosition(PointPositionX - 20, PointPositionY);

		sZERO.setPosition(PointPositionX, PointPositionY);
		sONE.setPosition(PointPositionX, PointPositionY);
		sTWO.setPosition(PointPositionX, PointPositionY);
		sTHREE.setPosition(PointPositionX, PointPositionY);
		sFOUR.setPosition(PointPositionX, PointPositionY);
		sFIVE.setPosition(PointPositionX, PointPositionY);
		sSIX.setPosition(PointPositionX, PointPositionY);
		sSEVEN.setPosition(PointPositionX, PointPositionY);
		sEIGHT.setPosition(PointPositionX, PointPositionY);
		sNINE.setPosition(PointPositionX, PointPositionY);
		switch (FlappPointPositionYPoints)
		{
		case 30:
			window.draw(sTHREEDouble);
			window.draw(sZERO);
			break;
		case 31:
			window.draw(sTHREEDouble);
			window.draw(sONE);
			break;
		case 32:
			window.draw(sTHREEDouble);
			window.draw(sTWO);
			break;
		case 33:
			window.draw(sTHREEDouble);
			window.draw(sTHREE);
			break;
		case 34:
			window.draw(sTHREEDouble);
			window.draw(sFOUR);
			break;
		case 35:
			window.draw(sTHREEDouble);
			window.draw(sFIVE);
			break;
		case 36:
			window.draw(sTHREEDouble);
			window.draw(sSIX);
			break;
		case 37:
			window.draw(sTHREEDouble);
			window.draw(sSEVEN);
			break;
		case 38:
			window.draw(sTHREEDouble);
			window.draw(sEIGHT);
			break;
		case 39:
			window.draw(sTHREEDouble);
			window.draw(sNINE);
			break;
		}
	}
}
