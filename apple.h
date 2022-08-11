#pragma once
#include "point.h"
#include <vector>

class Apple
{
	Point _appleCoordinates;
	int _fieldWidth, _fieldHeight;

public:
	Apple(int fieldWidth, int fieldLength, std::vector<Point> occupiedCells);

	Point getCoordinates();
	void generateNewCoordinates(std::vector<Point> occupiedCells);
};
