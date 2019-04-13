#include "rectangle.hpp"
#include <iostream>
#include <cassert>

drozdov::Rectangle::Rectangle (double width, double height, const point_t &pos):
  width_(width),
  height_(height),
  pos_(pos)
{
  assert(width > 0.0);
  assert(height > 0.0);
}

void drozdov::Rectangle::printData() const
{
  std::cout << "\nWidth: " << width_ << "\tHeight: " << height_;
  std::cout << "\nPosition: (" << pos_.x << ';' << pos_.y << ')' << std::endl;
}

double drozdov::Rectangle::getArea() const
{
  return (width_ * height_);
}

rectangle_t drozdov::Rectangle::getFrameRect() const
{
  return rectangle_t{width_, height_, pos_};
}

void drozdov::Rectangle::scale(double factor)
{
  assert(factor > 0.0);
  width_ *= factor;
  height_ *= factor;
}

void drozdov::Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void drozdov::Rectangle::move(const point_t &dot)
{
  pos_ = dot;
}
