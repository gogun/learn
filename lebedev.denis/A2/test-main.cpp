#define BOOST_TEST_MODULE
#include "rectangle.hpp"
#include "circle.hpp"
#include "polygon.hpp"
#include <boost/test/included/unit_test.hpp>
#include <stdexcept>

BOOST_AUTO_TEST_SUITE(TestCircle)

const double fault = 0.001;

BOOST_AUTO_TEST_CASE(TestCircleAfterMove)
{
  lebedev::Circle c1(3.00, {1.00, 3.00 });
  const double AreaBefore = c1.getArea();
  const lebedev::rectangle_t frameBefore = c1.getFrameRect();
  c1.move(2.00, 5.4);
  const double AreaAfterMove = c1.getArea();
  const lebedev::rectangle_t frameAfterMove = c1.getFrameRect();
  BOOST_CHECK_CLOSE(frameBefore.height, frameAfterMove.height, fault);
  BOOST_CHECK_CLOSE(frameBefore.width, frameAfterMove.width, fault);
  BOOST_CHECK_CLOSE(AreaBefore, AreaAfterMove, fault);
}

BOOST_AUTO_TEST_CASE(TestCiecleAfterMovePos)
{
  lebedev::Circle c1(3.00, {1.00, 3.00 });
  const double AreaBefore = c1.getArea();
  const lebedev::rectangle_t frameBefore = c1.getFrameRect();
  c1.move({3.00, 4.00});
  const double AreaAfterMove = c1.getArea();
  const lebedev::rectangle_t frameAfterMove = c1.getFrameRect();
  BOOST_CHECK_CLOSE(frameBefore.height, frameAfterMove.height, fault);
  BOOST_CHECK_CLOSE(frameBefore.width, frameAfterMove.width, fault);
  BOOST_CHECK_CLOSE(AreaBefore, AreaAfterMove, fault);
}

BOOST_AUTO_TEST_CASE(TestCircleScale)
{
  lebedev::Circle c1(3.00, {1.00, 3.00});
  const double AreaBeforeScale = c1.getArea();
  const double multiplier = 2.0;
  const double squareMult = multiplier * multiplier;
  c1.scale(multiplier);
  const double AreaAfterScale = c1.getArea();
  BOOST_CHECK_CLOSE(AreaBeforeScale * squareMult, AreaAfterScale, fault);
}

BOOST_AUTO_TEST_CASE(TestCircleInvalidParametrs)
{
  BOOST_CHECK_THROW(lebedev::Circle(-1.5, {1.00, 3.00}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(TestCircleInvalidMultiplier)
{
  lebedev::Circle c1(1.5, {1.00, 3.00});
  BOOST_CHECK_THROW(c1.scale(-1.5), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(TestRectangle)

const double fault = 0.001;

BOOST_AUTO_TEST_CASE(TestRectangleAfterMove)
{
  lebedev::Rectangle r1(3.00, 4.00, {5.00, 4.00});
  const double AreaBefore = r1.getArea();
  const lebedev::rectangle_t frameBefore = r1.getFrameRect();
  r1.move(2.00, 5.4);
  const double AreaAfterMove = r1.getArea();
  const lebedev::rectangle_t frameAfterMove = r1.getFrameRect();
  BOOST_CHECK_CLOSE(frameBefore.height, frameAfterMove.height, fault);
  BOOST_CHECK_CLOSE(frameBefore.width, frameAfterMove.width, fault);
  BOOST_CHECK_CLOSE(AreaBefore, AreaAfterMove, fault);
}

BOOST_AUTO_TEST_CASE(TestRectangleAfterMovePos)
{
  lebedev::Rectangle r1(3.00, 4.00, {5.00, 4.00 });
  const double AreaBefore = r1.getArea();
  const lebedev::rectangle_t frameBefore = r1.getFrameRect();
  r1.move({3.00, 4.00});
  const double AreaAfterMove = r1.getArea();
  const lebedev::rectangle_t frameAfterMove = r1.getFrameRect();
  BOOST_CHECK_CLOSE(frameBefore.height, frameAfterMove.height, fault);
  BOOST_CHECK_CLOSE(frameBefore.width, frameAfterMove.width, fault);
  BOOST_CHECK_CLOSE(AreaBefore, AreaAfterMove, fault);
}

BOOST_AUTO_TEST_CASE(TestRectangleScale)
{
  lebedev::Rectangle r1(3.00, 4.00, {5.00, 4.00 });
  const double AreaBeforeScale = r1.getArea();
  const double multiplier = 2.0;
  const double squareMult = multiplier * multiplier;
  r1.scale(multiplier);
  const double AreaAfterScale = r1.getArea();
  BOOST_CHECK_CLOSE(AreaBeforeScale * squareMult, AreaAfterScale, fault);
}

BOOST_AUTO_TEST_CASE(TestRectangleInvalidParametrs)
{
  BOOST_CHECK_THROW(lebedev::Rectangle (-3.00, 4.00, {5.00, 4.00 }), std::invalid_argument);
  BOOST_CHECK_THROW(lebedev::Rectangle (3.00, -4.00, {5.00, 4.00 }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(TestRectangleInvalidCoefficient)
{
  lebedev::Rectangle r1(3.00, 4.00, {5.00, 4.00 });
  BOOST_CHECK_THROW(r1.scale(-1.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(PolygonTest)

const double fault = 0.001;

BOOST_AUTO_TEST_CASE(TestPolygonAfterMove)
{
  lebedev::point_t shape[] = {{4.0, 1.0}, {7.0, 3.0}, {6.0, 8.0}, {2.0, 4.0}};
  size_t qtyVertex = sizeof(shape) / sizeof(shape[0]);
  lebedev::Polygon poly(qtyVertex, shape);
  const double AreaBefore = poly.getArea();
  const lebedev::rectangle_t frameBefore = poly.getFrameRect();
  poly.move(2.00, 5.4);
  const double AreaAfterMove = poly.getArea();
  const lebedev::rectangle_t frameAfterMove = poly.getFrameRect();
  BOOST_CHECK_CLOSE(frameBefore.height, frameAfterMove.height, fault);
  BOOST_CHECK_CLOSE(frameBefore.width, frameAfterMove.width, fault);
  BOOST_CHECK_CLOSE(AreaBefore, AreaAfterMove, fault);
}

BOOST_AUTO_TEST_CASE(TestPolygonAfterMovePos)
{
  lebedev::point_t shape[] = {{4.0, 1.0}, {7.0, 3.0}, {6.0, 8.0}, {2.0, 4.0}};
  size_t qtyVertex = sizeof(shape) / sizeof(shape[0]);
  lebedev::Polygon poly(qtyVertex, shape);
  const double AreaBefore = poly.getArea();
  const lebedev::rectangle_t frameBefore = poly.getFrameRect();
  poly.move({3.00, 4.00});
  const double AreaAfterMove = poly.getArea();
  const lebedev::rectangle_t frameAfterMove = poly.getFrameRect();
  BOOST_CHECK_CLOSE(frameBefore.height, frameAfterMove.height, fault);
  BOOST_CHECK_CLOSE(frameBefore.width, frameAfterMove.width, fault);
  BOOST_CHECK_CLOSE(AreaBefore, AreaAfterMove, fault);
}

BOOST_AUTO_TEST_CASE(TestPolygonScale)
{
  lebedev::point_t shape[] = {{4.0, 1.0}, {7.0, 3.0}, {6.0, 8.0}, {2.0, 4.0}};
  size_t qtyVertex = sizeof(shape) / sizeof(shape[0]);
  lebedev::Polygon poly(qtyVertex, shape);
  const double AreaBeforeScale = poly.getArea();
  const double multiplier = 2.0;
  const double squareMult = multiplier * multiplier;
  poly.scale(multiplier);
  const double AreaAfterScale = poly.getArea();
  BOOST_CHECK_CLOSE(AreaBeforeScale * squareMult, AreaAfterScale, fault);
}

BOOST_AUTO_TEST_CASE(TestPolygonInvalidParametrs)
{
  lebedev::point_t shape[] = {{4.0, 1.0}, {7.0, 3.0}};
  size_t qtyVertex = sizeof(shape) / sizeof(shape[0]);
  BOOST_CHECK_THROW(lebedev::Polygon poly(qtyVertex, shape), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(TestPolygonInvalidCoefficient)
{
  lebedev::point_t shape[] = {{4.0, 1.0}, {7.0, 3.0}, {6.0, 8.0}, {2.0, 4.0}};
  size_t qtyVertex = sizeof(shape) / sizeof(shape[0]);
  lebedev::Polygon poly(qtyVertex, shape);
  BOOST_CHECK_THROW(poly.scale(-5.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
