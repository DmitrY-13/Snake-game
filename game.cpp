#include "game.h"

Game::Game(int fieldWidth, int fieldHeight, int cellSize, sf::RenderWindow* pWindow, sf::Sound eatSound, sf::Font font)
{
	_fieldWidth = fieldWidth;
	_fieldHeight = fieldHeight;
	_cellSize = cellSize;
	_pWindow = pWindow;
	_eatSound = eatSound;
	_font = font;

	_snakeHeadSprite = sf::RectangleShape(sf::Vector2f(_cellSize, _cellSize));
	_snakeHeadSprite.setFillColor(sf::Color(255, 175, 0));

	_snakeBodySprite = sf::RectangleShape(sf::Vector2f(_cellSize, _cellSize));
	_snakeBodySprite.setFillColor(sf::Color(255, 255, 0));

	_appleSprite = sf::RectangleShape(sf::Vector2f(_cellSize, _cellSize));
	_appleSprite.setFillColor(sf::Color(255, 0, 0));
}

bool Game::start(gameDifficulty difficulty)
{
	int score = 0;
	sf::Text scoreText(getScoreString(score), _font, 30);
	sf::Color background(45, 45, 45);
	Snake snake(Point(5, _fieldHeight / 2), snakeDirection::RIGHT, 4);
	Apple apple(_fieldWidth, _fieldHeight, snake.get—oordinates());
	sf::Clock moveTimer;
	while (true) {
		sf::Event event;
		while (_pWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				return true;
			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code) {
				case sf::Keyboard::Up:
					snake.changeDirection(snakeDirection::UP);
					break;
				case sf::Keyboard::Down:
					snake.changeDirection(snakeDirection::DOWN);
					break;
				case sf::Keyboard::Left:
					snake.changeDirection(snakeDirection::LEFT);
					break;
				case sf::Keyboard::Right:
					snake.changeDirection(snakeDirection::RIGHT);
					break;
				}
			}
		}

		if (moveTimer.getElapsedTime().asSeconds() >= _movingTimeOptions[difficulty]) {
			snake.move();
			moveTimer.restart();
		}

		if (snake.wasEaten(apple.get—oordinates())) {
			apple.generateNew—oordinates(snake.get—oordinates());
			scoreText.setString(getScoreString(++score));
			_eatSound.play();
		}

		if (snake.isSuicide() || isWall—ollision(snake.get—oordinates()[0])) {
			if (_bestScore[difficulty] < score)
				_bestScore[difficulty] = score;
			return false;
		}

		drawFrame(background, snake.get—oordinates(), apple.get—oordinates(), scoreText);
	}
}

void Game::setBestScore(int bestScore[3])
{
	for (int i = 0; i < 3; i++)
		_bestScore[i] = bestScore[i];
}

int Game::getBestScore(gameDifficulty difficulty)
{
	return _bestScore[difficulty];
}

inline bool Game::isWall—ollision(Point snakeHead—oordinates)
{
	return snakeHead—oordinates < Point(0, 0) || snakeHead—oordinates > Point(_fieldWidth - 1, _fieldHeight - 1);
}

inline std::string Game::getScoreString(int score)
{
	return std::string("SCORE: " + std::to_string(score));
}

void Game::drawFrame(sf::Color background, std::vector<Point> snakeCoordinates, Point apple—oordinates, sf::Text scoreText)
{
	_pWindow->clear(background);

	_snakeHeadSprite.setPosition(snakeCoordinates[0].x * _cellSize, snakeCoordinates[0].y * _cellSize);
	_pWindow->draw(_snakeHeadSprite);

	for (int i = 1; i < snakeCoordinates.size(); i++) {
		_snakeBodySprite.setPosition(snakeCoordinates[i].x * _cellSize, snakeCoordinates[i].y * _cellSize);
		_pWindow->draw(_snakeBodySprite);
	}

	_appleSprite.setPosition(apple—oordinates.x * _cellSize, apple—oordinates.y * _cellSize);
	_pWindow->draw(_appleSprite);

	_pWindow->draw(scoreText);

	_pWindow->display();
}
