#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace zakharova
{
  class Shape
  {
  public:
    virtual ~Shape() = default;

    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void move(point_t newpos) = 0;
    virtual void scale(double factor) = 0;

    virtual void getInfo() const = 0;
  };
}

#endif // SHAPE_HPP
