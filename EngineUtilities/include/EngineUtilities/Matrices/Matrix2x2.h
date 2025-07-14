#pragma once

#include <cmath>
#include <string>
#include <sstream>

using namespace std;

namespace EngineUtilities::Matrices {

  /**
   * @brief Esta clase representa una matriz de 2x2. Útil para transformaciones
   * simples en 2D como rotaciones, escalados y combinaciones.
   */
  class
    Matrix2x2 {
  public:
    Matrix2x2() {
      // Inicia como matriz identidad (no hace nada)
      m[0][0] = 1.0f; m[0][1] = 0.0f;
      m[1][0] = 0.0f; m[1][1] = 1.0f;
    }

    Matrix2x2(float a, float b, float c, float d) {
      m[0][0] = a; m[0][1] = b;
      m[1][0] = c; m[1][1] = d;
    }

    ~Matrix2x2() {
    }

    float
      determinant() const {
      return m[0][0] * m[1][1] - m[0][1] * m[1][0];
    }

    Matrix2x2
      transpose() const {
      return Matrix2x2(
        m[0][0], m[1][0],
        m[0][1], m[1][1]
      );
    }

    Matrix2x2
      inverse() const {
      float det = determinant();
      if (det == 0.0f) return Matrix2x2(); // Si no se puede invertir, regresamos identidad

      float invDet = 1.0f / det;
      return Matrix2x2(
        m[1][1] * invDet, -m[0][1] * invDet,
        -m[1][0] * invDet, m[0][0] * invDet
      );
    }

    string
      toString() const {
      stringstream ss;
      ss << "[" << m[0][0] << ", " << m[0][1] << "]\n";
      ss << "[" << m[1][0] << ", " << m[1][1] << "]";
      return ss.str();
    }

  public:
    float m[2][2];
  };

}

