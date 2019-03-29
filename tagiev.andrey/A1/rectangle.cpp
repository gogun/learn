#include "rectangle.hpp"
#include <cassert>
#include "base-types.hpp"

Rectangle::Rectangle(const point_t &center, double width, double height):
  center_(center),
  width_(width),
  height_(height)
{
  assert((height>0) && (width>0));
}
double Rectangle::getArea() const
{
  return width_*height_;
}
rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}
void Rectangle::move(double dX, double dY)
{
  center_.x += dX;
  center_.y += dY;
}
void Rectangle::move(point_t newPoint)
{
  center_ = newPoint;
}
