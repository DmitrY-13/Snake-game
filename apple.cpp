#include "apple.h"

Apple::Apple(int fieldWidth, int fieldHeight, std::vector<Point> occupiedCells)
{
	_fieldWidth = fieldWidth;
	_fieldHeight = fieldHeight;
	generateNewCoordinates(occupiedCells);
}

Point Apple::getCoordinates()
{
	return _appleCoordinates;
}

void Apple::generateNewCoordinates(std::vector<Point> occupiedCells)
{
TRY_GENERATE:
	_appleCoordinates.x = rand() % _fieldWidth;
	_appleCoordinates.y = rand() % _fieldHeight;
	for (Point cell : occupiedCells)
		if (_appleCoordinates == cell)
			goto TRY_GENERATE;
}
