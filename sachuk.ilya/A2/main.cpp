#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  sachuk::Circle circle({2, 3}, 10); //Создание круга
  sachuk::Shape *ptr_shape = &circle;
  ptr_shape->printInfo();

  ptr_shape->move({7, 8}); //Перемещение в точку
  ptr_shape->printInfo();

  ptr_shape->move(4, 5); //Смещение по осям
  ptr_shape->printInfo();
  
  std::cout << "After scale" << std::endl;
  ptr_shape->scale(6); //Масштабирование
  ptr_shape->printInfo();

  sachuk::Rectangle rectangle({5, 8}, 10, 14); //Создание прямоугольника
  ptr_shape = &rectangle;
  ptr_shape->printInfo();

  ptr_shape->move({8, 3}); //Перемещение в точку
  ptr_shape->printInfo();

  ptr_shape->move(10, 23); //Перемещение по осям
  ptr_shape->printInfo();

  std::cout << "After scale" << std::endl;
  ptr_shape->scale(5); //Масштабирование
  ptr_shape->printInfo();
  return 0;
}
