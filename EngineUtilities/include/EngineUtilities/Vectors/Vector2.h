#pragma once

#include <cmath>
#include <string>
#include <sstream>

using namespace std;

namespace EngineUtilities::Vectors {

  class
    Vector2 {
  public:
    Vector2() : x(0.0f), y(0.0f) {
    }

    Vector2(float x, float y) : x(x), y(y) {
    }

    ~Vector2() {
    }

    float
      length() const {
      return sqrt(x * x + y * y);
    }

    void
      normalize() {
      float len = length();
      if (len != 0.0f) {
        x /= len;
        y /= len;
      }
    }

    Vector2
      normalized() const {
      float len = length();
      if (len == 0.0f) return Vector2(0.0f, 0.0f);
      return Vector2(x / len, y / len);
    }

    Vector2
      operator+(const Vector2& other) const {
      return Vector2(x + other.x, y + other.y);
    }

    Vector2
      operator-(const Vector2& other) const {
      return Vector2(x - other.x, y - other.y);
    }

    Vector2
      operator*(float scalar) const {
      return Vector2(x * scalar, y * scalar);
    }

    Vector2
      operator/(float scalar) const {
      return (scalar != 0.0f) ? Vector2(x / scalar, y / scalar) : Vector2(0.0f, 0.0f);
    }

    string
      toString() const {
      stringstream ss;
      ss << "(" << x << ", " << y << ")";
      return ss.str();
    }

  public:
    float x;
    float y;
  };

}
