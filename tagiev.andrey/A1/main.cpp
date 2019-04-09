#include <iostream>
#include <cassert>

#include "circle.hpp"
#include "rectangle.hpp"

void printInfo(const Shape *shape)
{
  assert(shape != nullptr);

  const rectangle_t frame = shape->getFrameRect();

  std::cout << "Area of shape: " << shape->getArea() << '\n';
  std::cout << "Width of frame: " << frame.width << '\n';
  std::cout << "Height of frame: " << frame.height << '\n';
  std::cout << "Center: " << frame.pos.x << ", " << frame.pos.y << "\n\n";
}

int main()
{
  Rectangle rectangle({123.0, 100.0}, 5.0, 3.0);

  printInfo(&rectangle);
  const point_t newCenter1 = {1.0, 2.0};
  rectangle.move(newCenter1);
  rectangle.move(10, 20);
  printInfo(&rectangle);

  Circle circle({11.1, 12.2}, 4.4);

  printInfo(&circle);
  const point_t newCenter2 = {10.0, 20.0};
  circle.move(newCenter2);
  circle.move(1, 2);
  printInfo(&circle);

  return 0;
}
