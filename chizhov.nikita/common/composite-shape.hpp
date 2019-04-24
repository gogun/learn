#ifndef CN_A3_COMPOSITESHAPE
#define CN_A3_COMPOSITESHAPE

#include "shape.hpp"

namespace chizhov
{
  class CompositeShape : public Shape {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape&);
    CompositeShape(CompositeShape&&);
    CompositeShape(Shape&);
    ~CompositeShape();

    CompositeShape& operator =(const CompositeShape&);
    CompositeShape& operator =(CompositeShape&&);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double, double) override;
    void move(point_t) override;
    void scale(double) override;

    void addShape(Shape&);
    void deleteShape(const Shape&);

  private:
    Shape** shapes_;
    int count_;

    inline void copyFromSource(const CompositeShape&);
  };
}

#endif
