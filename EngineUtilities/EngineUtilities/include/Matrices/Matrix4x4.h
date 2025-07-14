#pragma once

#include <cmath>
#include <string>
#include <sstream>

using namespace std;

namespace EngineUtilities::Matrices {

  class
    Matrix4x4 {
  public:
    Matrix4x4() {
      for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
          m[i][j] = (i == j) ? 1.0f : 0.0f;
    }

    ~Matrix4x4() {
    }

    Matrix4x4
      transpose() const {
      Matrix4x4 result;
      for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
          result.m[i][j] = m[j][i];
      return result;
    }

    // Para este ejemplo, la inversa no está completamente implementada
    // Podrías agregarla si el profe lo pide, pero no es trivial como en 2x2

    string
      toString() const {
      stringstream ss;
      for (int i = 0; i < 4; ++i) {
        ss << "[";
        for (int j = 0; j < 4; ++j) {
          ss << m[i][j];
          if (j < 3) ss << ", ";
        }
        ss << "]\n";
      }
      return ss.str();
    }

  public:
    float m[4][4];
  };

}

