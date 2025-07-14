#pragma once

#include <cmath>
#include <string>
#include <sstream>

using namespace std;

namespace EngineUtilities::Matrices {

  class
    Matrix3x3 {
  public:
    Matrix3x3() {
      for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
          m[i][j] = (i == j) ? 1.0f : 0.0f;
    }

    Matrix3x3(float values[3][3]) {
      for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
          m[i][j] = values[i][j];
    }

    ~Matrix3x3() {
    }

    float
      determinant() const {
      return
        m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) -
        m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
        m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
    }

    Matrix3x3
      transpose() const {
      Matrix3x3 result;
      for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
          result.m[i][j] = m[j][i];
      return result;
    }

    string
      toString() const {
      stringstream ss;
      for (int i = 0; i < 3; ++i) {
        ss << "[";
        for (int j = 0; j < 3; ++j) {
          ss << m[i][j];
          if (j < 2) ss << ", ";
        }
        ss << "]\n";
      }
      return ss.str();
    }

  public:
    float m[3][3];
  };

}

