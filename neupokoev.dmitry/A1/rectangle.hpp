#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(rectangle_t parameters);
  void move(const point_t &point) override;
  void move(double moveY, double moveX) override;
  void writeParameters() const override;
  double getArea() const override;
  rectangle_t getFrameRect() const override;

private:
  rectangle_t parameters_;
};

#endif
