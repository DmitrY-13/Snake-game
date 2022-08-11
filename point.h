#pragma once

struct Point
{
	int x, y;

	Point(int x = 0, int y = 0);

	Point operator+(Point other);
	void operator=(Point other);
	void operator+=(Point other);
	bool operator<(Point other);
	bool operator>(Point other);
	bool operator==(Point other);
};
