#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(point_t position, double width, double height) :
  center_(position),
  width_(width),
  height_(height) {
  assert((width_ >= 0.0) && (height_ >= 0.0));
}

Rectangle::Rectangle(double x, double y, double width, double height) :
  Rectangle({x, y}, width, height) {
}

Rectangle::Rectangle(double x, double y, double side) :
  Rectangle({x, y}, side, side) {
}

Rectangle::Rectangle(point_t position, double side) :
  Rectangle(position, side, side) {
}

void Rectangle::move(point_t position) {
  center_ = position;
}

void Rectangle::move(double newx, double newy) {
  center_.x = newx;
  center_.y = newy;
}

double Rectangle::getArea() const {
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const {
  return {width_, height_, center_};
}
