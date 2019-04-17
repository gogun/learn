#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(point_t vertex1, point_t vertex2, point_t vertex3);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void changeVertex(double dx, double dy);
  void move(const point_t & point) override;
  void move(double dx, double dy) override;
  void showCoord();
  void printCenter();
private:
  point_t vertex_1;
  point_t vertex_2;
  point_t vertex_3;
  point_t center_;
  point_t getCenter() const;
  double getVector(const point_t & vertex1, const point_t & vertex2) const;
};

#endif
