#include "rectangle.hpp"
#include <cassert>
#include <iostream>

Rectangle::Rectangle(const double & width, const double & height, const point_t & point) :
  rect_({width, height, point})
{
  assert(height > 0.0);
  assert(width > 0.0);
}

void Rectangle::showInfo() const
{
  std::cout << "Information about rectangle\n";
  std::cout << "Width: " << rect_.width;
  std::cout << "\nHeight: " << rect_.height << "\n";
  showCords();
  std::cout << "Area: " << getArea() << "\n";
}

double Rectangle::getArea() const
{
  return (rect_.width * rect_.height);
}

void Rectangle::move(const point_t & point)
{
  rect_.pos = point;
}

void Rectangle::move(const double & dX, const double & dY)
{
  rect_.pos.x += dX;
  rect_.pos.y += dY;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {rect_.width, rect_.height, rect_.pos};
}

void Rectangle::showFrameRect() const
{
  rectangle_t rect = getFrameRect();
  std::cout << "\nBounded rectangle";
  std::cout << "\nWidth: " << rect.width;
  std::cout << "\nHeight: " << rect.height << "\n";
  showCords();
}

void Rectangle::showCords() const
{
  std::cout << "Center: ";
  std::cout << "\n X: " << rect_.pos.x;
  std::cout << "\n Y: " << rect_.pos.y << "\n";
}
