#ifndef A1_CIRCLE_HPP
#define A1_CIRCLE_HPP
#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(const double radius, const point_t& center);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& point) override;
  void move(double dx, double dy) override;
  void printShapeInfo() const override;

private:
  double radius_;
  point_t pos_;
};

#endif

