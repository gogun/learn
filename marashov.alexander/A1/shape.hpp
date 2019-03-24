#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual point_t getCenter() const = 0;
    virtual void move(const point_t& pos) = 0;
    virtual void move(double dltX, double dltY) = 0;
    virtual ~Shape() = default;
};

#endif //SHAPE_HPP
