#include "circle.hpp"
#include <cmath>
#include <stdexcept>

Circle::Circle(double radius, point_t center) :
  radius_(radius),
  center_(center)
{
  if (radius_ < 0.0)
  {
    throw std::invalid_argument("Invalid radius");
  }
}

double Circle::getArea() const noexcept
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const noexcept
{
  rectangle_t frameRect = {2 * radius_, 2 * radius_, center_};
  return frameRect;
}

void Circle::move(double dx, double dy) noexcept
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::move(point_t newPos) noexcept
{
  center_ = newPos;
}
