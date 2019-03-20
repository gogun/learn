#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;

  virtual float getArea() const  = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(const point_t & newCentre) = 0;
  virtual void move(float newX, float newY) = 0;

  const point_t & getCentre() const
  { 
    return centre_; 
  }
protected:
  point_t centre_;
private:
};

#endif // !SHAPE_HPP
