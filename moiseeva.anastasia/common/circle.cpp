#include "circle.hpp"

#include <cmath>
#include <stdexcept>

moiseeva::Circle::Circle(const point_t &dot, double rad):
  center_(dot),
  radius_(rad)
{
  if (radius_ < 0.0)
  {
    throw std::invalid_argument("Circle radius cannot be less than zero.");
  }
}

double moiseeva::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

moiseeva::rectangle_t moiseeva::Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, center_};
}

void moiseeva::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void moiseeva::Circle::move(const point_t &point)
{
  center_ = point;
}

void moiseeva::Circle::scale(double coefficient)
{
  if (coefficient < 0.0)
  {
    throw std::invalid_argument("Radius cannot be less than zero.");
  }
  else
  {
    radius_ *= coefficient;
  }
}
