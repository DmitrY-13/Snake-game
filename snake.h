#pragma once
#include "point.h"
#include <vector>

enum snakeDirection
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};
snakeDirection operator!(snakeDirection direction);

class Snake
{
	std::vector<Point> _coordinates;
	snakeDirection _direction;
	bool _needGrow = false, _canTakeNewDirection = true;

public:
	Snake(Point head, snakeDirection direction, int length);

	void changeDirection(snakeDirection newDirection);
	bool wasEaten(Point food—oordinates);
	void move();
	bool isSuicide();
	std::vector<Point> get—oordinates();

private:
	Point getShift(snakeDirection direction);
};
