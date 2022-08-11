#include "point.h"

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

Point Point::operator+(Point other)
{
    return Point(this->x + other.x, this->y + other.y);
}

void Point::operator=(Point other)
{
    this->x = other.x;
    this->y = other.y;
}

void Point::operator+=(Point other)
{
    this->x += other.x;
    this->y += other.y;
}

bool Point::operator<(Point other)
{
    return this->x < other.x || this->y < other.y;
}

bool Point::operator>(Point other)
{
    return this->x > other.x || this->y > other.y;
}

bool Point::operator==(Point other)
{
    return this->x == other.x && this->y == other.y;
}
