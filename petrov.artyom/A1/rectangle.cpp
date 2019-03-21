#include "rectangle.hpp"
#include <stdexcept>

Rectangle::Rectangle(rectangle_t rectangle) :
  rectangle_(rectangle)
{

}

Rectangle::Rectangle(point_t centre, double width, double height)
{
  if (width <= 0)
  {
    throw std::invalid_argument("Width must be greater than 0");
  }

  if (height <= 0)
  {
    throw std::invalid_argument("Height must be greater than 0");
  }

  rectangle_ = rectangle_t {width, height, centre };
}

double Rectangle::getArea() const
{
  return rectangle_.height * rectangle_.width;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_;
}

void Rectangle::move(const point_t & centre)
{
  rectangle_.pos = centre;
}

void Rectangle::move(double dx, double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.x += dy;
}
