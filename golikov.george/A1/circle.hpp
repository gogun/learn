#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
  public:
    float m_radius;
    point_t m_center;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &pos) override;
    void move(const float dltX, const float dltY) override;
};

#endif
