//
// Created by Артур on 18.03.2019.
//

#ifndef A1_SHAPE_HPP
#define A1_SHAPE_HPP

#include "base-types.hpp"

namespace nurtdinov
{
  class Shape
  {
  public:

    virtual ~Shape() = default;

    virtual double getArea() const = 0;

    virtual rectangle_t getFrameRect() const = 0;

    virtual void move(const point_t &point) = 0;

    virtual void move(double dx, double dy) = 0;

    virtual point_t getCenter() const = 0;

    virtual void scale(double) = 0;
  };
}

#endif //A1_SHAPE_HPP
