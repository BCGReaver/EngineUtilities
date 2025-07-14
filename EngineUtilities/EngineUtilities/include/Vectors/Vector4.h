#pragma once

#include <cmath>
#include <string>
#include <sstream>

using namespace std;

namespace EngineUtilities::Vectors {

  class
    Vector4 {
  public:
    Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {
    }

    Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {
    }

    ~Vector4() {
    }

    float
      length() const {
      return sqrt(x * x + y * y + z * z + w * w);
    }

    void
      normalize() {
      float len = length();
      if (len != 0.0f) {
        x /= len;
        y /= len;
        z /= len;
        w /= len;
      }
    }

    Vector4
      normalized() const {
      float len = length();
      if (len == 0.0f) return Vector4(0.0f, 0.0f, 0.0f, 0.0f);
      return Vector4(x / len, y / len, z / len, w / len);
    }

    Vector4
      operator+(const Vector4& other) const {
      return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    Vector4
      operator-(const Vector4& other) const {
      return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    Vector4
      operator*(float scalar) const {
      return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
    }

    Vector4
      operator/(float scalar) const {
      return (scalar != 0.0f) ? Vector4(x / scalar, y / scalar, z / scalar, w / scalar) : Vector4(0.0f, 0.0f, 0.0f, 0.0f);
    }

    string
      toString() const {
      stringstream ss;
      ss << "(" << x << ", " << y << ", " << z << ", " << w << ")";
      return ss.str();
    }

  public:
    float x;
    float y;
    float z;
    float w;
  };

}

