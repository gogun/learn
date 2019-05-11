#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace kvashnin
{
  class Circle: public Shape
  {
  public:
    Circle(const point_t &pos, const double radius);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &pos) override;
    void move(const double dx, const double dy) override;
    void scale(double coefficient) override;
    void printInfo() const override;

  private:
    point_t pos_;
    double radius_;
  };
}
#endif
