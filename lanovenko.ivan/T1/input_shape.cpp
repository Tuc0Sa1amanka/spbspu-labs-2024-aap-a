#include "input_shape.hpp"
#include <cstddef>
#include <stdexcept>
#include <string>
#include "rectangle.hpp"
#include "traingle.hpp"

void lanovenko::getPoints(const size_t num_points, double* coords_array, point_t* points)
{
  for (size_t i = 0; i < num_points; i++)
  {
    size_t number = i * 2;
    points[i] = {coords_array[number], coords_array[number + 1]};
  }
}

lanovenko::Shape* lanovenko::inputRectangle(const char str[])
{
  const char* coords_str = str + 10;
  double coords_array[4]{};
  size_t pos = 0;
  for (size_t i = 0; i < 4; i++)
  {
    coords_array[i] = std::stod(coords_str, std::addressof(pos));
    coords_str += pos;
  }
  if (*coords_str != '\0')
  {
    throw std::invalid_argument("Wrong rectangle arguments!\n");
  }
  constexpr size_t num_points = 2;
  point_t points[num_points]{};
  getPoints(num_points, coords_array, points);
  return new Rectangle(points[0], points[1]);
}

lanovenko::Shape* lanovenko::inputTriangle(const char str[])
{
  const char* coords_str = str + 9;
  double coords_array[6]{};
  size_t pos = 0;
  for (size_t i = 0; i < 6; ++i)
  {
    coords_array[i] = std::stod(coords_str, std::addressof(pos));
    coords_str += pos;
  }
    if (*coords_str != '\0')
    {
        throw std::invalid_argument("Invalid TRIANGLE arguments");
    }
    constexpr size_t num_points = 3;
    point_t points[num_points]{};
    getPoints(num_points, coords_array, points);
    return new Triangle(points[0], points[1], points[2]);
}

