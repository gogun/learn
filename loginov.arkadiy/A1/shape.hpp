#ifndef SPBSPU_LABS_2019_SHAPE_HPP
#define SPBSPU_LABS_2019_SHAPE_HPP

#include "base-types.hpp"

class Shape {
public:
  virtual ~Shape() = default;

  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(double dx, double dy) = 0;
  virtual void move(const point_t &point) = 0;
};

#endif
