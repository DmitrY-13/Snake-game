#include "snake.h"

snakeDirection operator!(snakeDirection direction)
{
	switch (direction)
	{
	case UP:
		return DOWN;
	case DOWN:
		return UP;
	case LEFT:
		return RIGHT;
	case RIGHT:
		return LEFT;
	}
}

Snake::Snake(Point head, snakeDirection direction, int length)
{
	_direction = direction;

	_coordinates.push_back(Point(head));
	for (int i = 0; i < length - 1; i++)
		_coordinates.push_back(_coordinates[i] + getShift(!_direction));
}

void Snake::changeDirection(snakeDirection newDirection)
{
	if (_direction != !newDirection && _canTakeNewDirection) {
		_direction = newDirection;
		_canTakeNewDirection = false;
	}
}

bool Snake::wasEaten(Point foodCoordinates)
{
	if (foodCoordinates == _coordinates[0]) {
		_needGrow = true;
		return true;
	}
	return false;
}

void Snake::move()
{
	int bodyLastElemNum = _coordinates.size() - 1;

	if (_needGrow) {
		_coordinates.push_back(Point(_coordinates[bodyLastElemNum]));
		_needGrow = false;
	}

	for (int i = bodyLastElemNum; i > 0; i--)
		_coordinates[i] = _coordinates[i - 1];
	_coordinates[0] += getShift(_direction);

	_canTakeNewDirection = true;
}

bool Snake::isSuicide()
{
	for (int i = 4; i < _coordinates.size(); i++)
		if (_coordinates[0] == _coordinates[i])
			return true;
	return false;
}

std::vector<Point> Snake::getCoordinates()
{
	return _coordinates;
}

Point Snake::getShift(snakeDirection direction)
{
	switch (direction)
	{
	case UP:
		return Point(0, -1);
	case DOWN:
		return Point(0, 1);
	case LEFT:
		return Point(-1, 0);
	case RIGHT:
		return Point(1, 0);
	}
}
