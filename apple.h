#pragma once
#include "point.h"
#include <vector>

class Apple
{
	Point _apple—oordinates;
	int _fieldWidth, _fieldHeight;

public:
	Apple(int fieldWidth, int fieldLength, std::vector<Point> occupied—ells);

	Point get—oordinates();
	void generateNew—oordinates(std::vector<Point> occupied—ells);
};
