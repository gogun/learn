#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(double width, double height, const point_t &pos):
  width_(width),
  height_(height),
  pos_(pos)
{
  assert((width_ > 0.0) && (height_ > 0.0));
}

double Rectangle::getArea() const
{
  return width_*height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void Rectangle::move(const point_t &point)
{
  pos_ = point;
}

void Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
