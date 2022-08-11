#include "apple.h"

Apple::Apple(int fieldWidth, int fieldHeight, std::vector<Point> occupiedÑells)
{
	_fieldWidth = fieldWidth;
	_fieldHeight = fieldHeight;
	generateNewÑoordinates(occupiedÑells);
}

Point Apple::getÑoordinates()
{
	return _appleÑoordinates;
}

void Apple::generateNewÑoordinates(std::vector<Point> occupiedÑells)
{
TRY_GENERATE:
	_appleÑoordinates.x = rand() % _fieldWidth;
	_appleÑoordinates.y = rand() % _fieldHeight;
	for (Point cell : occupiedÑells)
		if (_appleÑoordinates == cell)
			goto TRY_GENERATE;
}
