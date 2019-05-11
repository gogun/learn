#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

Circle::Circle(double radius, const point_t & center) :
  radius_(radius),
  center_(center)

{
  assert(radius_ > 0.0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, center_};
}

void Circle::move(const point_t & center)
{
  center_ = center;
}

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}
