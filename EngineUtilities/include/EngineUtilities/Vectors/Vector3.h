#pragma once

#include <cmath>
#include <string>
#include <sstream>

using namespace std;

namespace EngineUtilities::Vectors {

  class
    Vector3 {
  public:
    Vector3() : x(0.0f), y(0.0f), z(0.0f) {
    }

    Vector3(float x, float y, float z) : x(x), y(y), z(z) {
    }

    ~Vector3() {
    }

    float
      length() const {
      return sqrt(x * x + y * y + z * z);
    }

    void
      normalize() {
      float len = length();
      if (len != 0.0f) {
        x /= len;
        y /= len;
        z /= len;
      }
    }

    Vector3
      normalized() const {
      float len = length();
      if (len == 0.0f) return Vector3(0.0f, 0.0f, 0.0f);
      return Vector3(x / len, y / len, z / len);
    }

    Vector3
      operator+(const Vector3& other) const {
      return Vector3(x + other.x, y + other.y, z + other.z);
    }

    Vector3
      operator-(const Vector3& other) const {
      return Vector3(x - other.x, y - other.y, z - other.z);
    }

    Vector3
      operator*(float scalar) const {
      return Vector3(x * scalar, y * scalar, z * scalar);
    }

    Vector3
      operator/(float scalar) const {
      return (scalar != 0.0f) ? Vector3(x / scalar, y / scalar, z / scalar) : Vector3(0.0f, 0.0f, 0.0f);
    }

    string
      toString() const {
      stringstream ss;
      ss << "(" << x << ", " << y << ", " << z << ")";
      return ss.str();
    }

  public:
    float x;
    float y;
    float z;
  };

}

