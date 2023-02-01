#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

class Point {
  public:
    double x;
    double y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

class Vector2D {
  public:
    Point endpoint;

    Vector2D(double x = 0, double y = 0) : endpoint(Point(x, y)) {}

    double magnitude() const {
      return sqrt(endpoint.x * endpoint.x + endpoint.y * endpoint.y);
    }

    void normalize() {
      double mag = magnitude();
      endpoint.x /= mag;
      endpoint.y /= mag;
    }

    double dot(const Vector2D &other) const {
      return endpoint.x * other.endpoint.x + endpoint.y * other.endpoint.y;
    }

    Vector2D operator+(const Vector2D &other) const {
      return Vector2D(endpoint.x + other.endpoint.x, endpoint.y + other.endpoint.y);
    }

    Vector2D operator-(const Vector2D &other) const {
      return Vector2D(endpoint.x - other.endpoint.x, endpoint.y - other.endpoint.y);
    }

    Vector2D operator*(double scalar) const {
      return Vector2D(endpoint.x * scalar, endpoint.y * scalar);
    }
};

int main() 
{
  Vector2D v1(3, 4), v2(1, 2);

  std::cout << "v1: " << v1.endpoint.x << " " << v1.endpoint.y << std::endl;
  std::cout << "v2: " << v2.endpoint.x << " " << v2.endpoint.y << std::endl;

  std::cout << "Magnitude of v1: " << v1.magnitude() << std::endl;
  std::cout << "Magnitude of v2: " << v2.magnitude() << std::endl;

  v1.normalize();
  v2.normalize();

  std::cout << "Normalized v1: " << v1.endpoint.x << " " << v1.endpoint.y << std::endl;
  std::cout << "Normalized v2: " << v2.endpoint.x << " " << v2.endpoint.y << std::endl;

  std::cout << "Dot product of v1 and v2: " << v1.dot(v2) << std::endl;

  Vector2D v3 = v1 + v2;
  std::cout << "v1 + v2: " << v3.endpoint.x << " " << v3.endpoint.y << std::endl;

  Vector2D v4 = v1 - v2;
  std::cout << "v1 - v2: " << v4.endpoint.x << " " << v4.endpoint.y << std::endl;

  system("Pause");
  return 0;
}

