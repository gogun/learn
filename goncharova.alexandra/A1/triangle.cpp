#include "triangle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Triangle::Triangle(const point_t &center, const point_t &pointA, const point_t &pointB) :
  center_(center),
  pointA_(pointA),
  pointB_(pointB),
  pointC_{3 * center_.x - pointB_.x - pointA_.x, 3 * center_.y - pointB_.y - pointA_.y}
{
  assert(fabs((pointB_.x - pointA_.x) * (center_.y - pointA_.y) 
      - (center_.x - pointA_.x) * (pointB_.y - pointA_.y)) > pow(10, -8));
}

double Triangle::getArea() const
{
  double square = fabs((pointA_.x - pointC_.x) * (pointB_.y - pointC_.y)
      - (pointB_.x - pointC_.x) * (pointA_.y - pointC_.y)) * 1 / 2;
  return square;
}

rectangle_t Triangle::getFrameRect() const
{
  double width = std::max(pointA_.x, std::max(pointB_.x, pointC_.x))
      - std::min(pointA_.x, std::min(pointB_.x, pointC_.x));
  double height = std::max(pointA_.y, std::max(pointB_.y, pointC_.y))
      - std::min(pointA_.y, std::min(pointB_.y, pointC_.y));

  point_t trCenter;
  trCenter.x = std::min(pointA_.x, std::min(pointB_.x, pointC_.x)) + width / 2;
  trCenter.y = std::min(pointA_.y, std::min(pointB_.y, pointC_.y)) + height / 2;

  return {trCenter, width, height};
}

void Triangle::move(const double dx, const double dy)
{
  pointA_.x += dx;
  pointB_.x += dx;
  pointC_.x += dx;

  pointA_.y += dy;
  pointB_.y += dy;
  pointC_.y += dy;

  center_.x += dx;
  center_.y += dy;
}

void Triangle::move(const point_t &newPoint)
{
  double dx = newPoint.x - center_.x;
  double dy = newPoint.y - center_.y;
  center_  = newPoint;

  pointA_.x += dx;
  pointB_.x += dx;
  pointC_.x += dx;

  pointA_.y += dy;
  pointB_.y += dy;
  pointC_.y += dy;
}

void Triangle::inform() const
{
  std::cout << "X: " << center_.x;
  std::cout << "\n Y: " << center_.y;
}
