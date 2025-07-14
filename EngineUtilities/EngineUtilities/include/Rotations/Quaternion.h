#pragma once

#include <cmath>
#include <string>
#include <sstream>

using namespace std;

namespace EngineUtilities::Rotations {

  /**
   * @brief Un quaternion es como una forma mágica de hacer rotaciones
   * en 3D sin que se buggeen las cosas como con matrices.
   * Evita problemas raros como el "gimbal lock".
   */
  class
    Quaternion {
  public:
    // ==== Constructores ====

    /**
     * @brief Constructor por defecto. Te deja el quaternion en (0, 0, 0, 1)
     * que es como decir “no hay rotación”.
     */
    Quaternion() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {
    }

    /**
     * @brief Constructor con valores directos si ya los tienes listos.
     */
    Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {
    }

    ~Quaternion() {
    }

    // ==== Métodos ====

    /**
     * @brief Normaliza el quaternion para que no se vuelva loco con las rotaciones.
     */
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

    /**
     * @brief Devuelve la magnitud total del quaternion.
     */
    float
      length() const {
      return sqrt(x * x + y * y + z * z + w * w);
    }

    /**
     * @brief Multiplicación de quaternions. Sirve para encadenar rotaciones.
     */
    Quaternion
      operator*(const Quaternion& other) const {
      return Quaternion(
        w * other.x + x * other.w + y * other.z - z * other.y,
        w * other.y - x * other.z + y * other.w + z * other.x,
        w * other.z + x * other.y - y * other.x + z * other.w,
        w * other.w - x * other.x - y * other.y - z * other.z
      );
    }

    /**
     * @brief Convierte el quaternion a texto, por si quieres imprimirlo.
     */
    string
      toString() const {
      stringstream ss;
      ss << "(" << x << ", " << y << ", " << z << ", " << w << ")";
      return ss.str();
    }

    /**
     * @brief Crea un quaternion a partir de un eje y un ángulo.
     * Súper útil para decir “rota X grados alrededor de este eje”.
     */
    static Quaternion
      fromAxisAngle(float axisX, float axisY, float axisZ, float angleDegrees) {
      float angleRad = angleDegrees * (3.14159265f / 180.0f); // conversión
      float halfAngle = angleRad / 2.0f;
      float sinHalf = sin(halfAngle);

      return Quaternion(
        axisX * sinHalf,
        axisY * sinHalf,
        axisZ * sinHalf,
        cos(halfAngle)
      );
    }

  public:
    float x;
    float y;
    float z;
    float w;
  };

}

