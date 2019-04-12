#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include "triangle.hpp"

double searchMax(double x, double y, double z)
{
  return std::max({ x,y,z });
}

double searchMin(double x, double y, double z)
{
  return std::min({x,y,z});
}

Triangle::Triangle(const point_t &a, const point_t &b, const point_t &c) :
  a_(a),
  b_(b),
  c_(c),
  pos_({ ((a.x + b.x + c.x) / 3), ((a.y + b.y + c.y) / 3) })
{
  assert(c.y != (a.y - b.y) / (a.x - b.x)*c.x + a.y - (a.y - b.y) / (a.x - b.x) * a.x);
}

double Triangle::getArea() const
{
  double p;
  p = (getAB() + getBC() + getCA()) * 0.5;
  return sqrt(p * (p - getAB()) * (p - getBC()) * (p - getCA()));
}

void Triangle::move(const double x, const double y)
{
  a_.x += x;
  b_.x += x;
  c_.x += x;
  a_.y += y;
  b_.y += y;
  c_.y += y;
}

void Triangle::move(const point_t &point)
{
  pos_ = point;
}

point_t Triangle::getA() const
{
  return a_;
}

point_t Triangle::getB() const
{
  return b_;
}

point_t Triangle::getC() const
{
  return c_;
}

point_t Triangle::getPos() const
{
  return pos_;
}

rectangle_t Triangle::getFrameRect() const
{
  double rMinX, rMinY, rMaxX, rMaxY;
  point_t rectangle_centre;
  rMaxX = searchMax(a_.x, b_.x, c_.x);
  rMaxY = searchMax(a_.y, b_.y, c_.y);
  rMinX = searchMin(a_.x, b_.x, c_.x);
  rMinY = searchMin(a_.y, b_.y, c_.y);
  rectangle_centre.x = (rMaxX + rMinX) / 2;
  rectangle_centre.y = (rMaxY + rMinY) / 2;
  return { rectangle_centre, rMaxX - rMinX, rMaxY - rMinY };
}

double Triangle::getAB() const
{
  return sqrt(pow((getB().x - getA().x), 2) + pow((getB().y - getA().y), 2));
}

double Triangle::getBC() const
{
  return sqrt(pow((getC().x - getB().x), 2) + pow((getC().y - getB().y), 2));
}

double Triangle::getCA() const
{
  return sqrt(pow((getA().x - getC().x), 2) + pow((getA().y - getC().y), 2));
}
