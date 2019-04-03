#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
  public:
    Shape(point_t pos);
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void displayData() const = 0;
    void move (double dx, double dy);
    void move (point_t dot);
  protected:
    point_t pos_;
};
#endif
