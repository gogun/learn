#include "circle.hpp"
#include <math.h>
#include <iostream>
#include <stdexcept>
#include "shape.hpp"
#include "base-types.hpp"

Circle::Circle (double Rcircle, point_t &cpoint):
  cR_(Rcircle),
  pos_(cpoint)
{
  assert(Rcircle > 0);
}

double Circle::getArea() const
{
  return M_PI * cR_ * cR_;
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * cR_, 2 * cR_, pos_};
}

void Circle::move(double mX, double mY)
{
  pos_.x += mX;
  pos_.y += mY;
}

void Circle::move(const point_t &point)
{
  pos_ = point;
}

void Circle::dataoutput() const
{
  std::cout << "area_of_circle_=" << getArea() << std::endl;
  std::cout << "framerect_width_height_X_Y_=" << getFrameRect().width << " " << getFrameRect().height << " ";
  std::cout << getFrameRect().pos_.x << " " << getFrameRect().pos_.y << std::endl;
  std::cout << "position_X_Y_" << pos_.x << " " << pos_.y << std::endl;
}
