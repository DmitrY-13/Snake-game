#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "point.h"
#include "snake.h"
#include "apple.h"

enum gameDifficulty
{
	EASY = 0,
	MEDIUM = 1,
	HARD = 2
};

class Game
{
	sf::RectangleShape _snakeHeadSprite;
	sf::RectangleShape _snakeBodySprite;
	sf::RectangleShape _appleSprite;

	int _fieldWidth, _fieldHeight, _cellSize;
	sf::RenderWindow* _pWindow;
	sf::Sound _eatSound;
	sf::Font _font;

	const float _movingTimeOptions[3]{0.1, 0.06, 0.02};

	int _bestScore[3]{ 0, 0, 0 };

public:
	Game(int fieldWidth, int fieldHeight, int cellSize, sf::RenderWindow* pWindow, sf::Sound eatSound, sf::Font font);
	
	bool start(gameDifficulty difficulty);
	void setBestScore(int bestScore[3]);
	int getBestScore(gameDifficulty difficulty);

private:
	inline bool isWall—ollision(Point snakeHead—oordinates);
	inline std::string getScoreString(int score);
	void drawFrame(sf::Color background, std::vector<Point> snakeCoordinates, Point apple—oordinates, sf::Text scoreText);
};
