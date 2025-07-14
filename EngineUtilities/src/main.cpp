#include <iostream>
#include "../include/EngineUtilities/Vectors/Vector2.h"
#include "../include/EngineUtilities/Vectors/Vector3.h"
#include "../include/EngineUtilities/Vectors/Vector4.h"
#include "../include/EngineUtilities/Rotations/Quaternion.h"
#include "../include/EngineUtilities/Matrices/Matrix2x2.h"
#include "../include/EngineUtilities/Matrices/Matrix3x3.h"
#include "../include/EngineUtilities/Matrices/Matrix4x4.h"
#include "../include/EngineUtilities/EngineMath/EngineMath.h"

using namespace std;
using namespace EngineUtilities::Vectors;
using namespace EngineUtilities::Rotations;
using namespace EngineUtilities::Matrices;
using namespace EngineUtilities::EngineMath;

int
main() {
  cout << "==== PRUEBA DE VECTORES ====" << endl;
  Vector2 vec2(3.0f, 4.0f);
  cout << "Vector2: " << vec2.toString() << " | Magnitud: " << vec2.length() << endl;

  Vector3 vec3(1.0f, 2.0f, 2.0f);
  cout << "Vector3: " << vec3.toString() << " | Magnitud: " << vec3.length() << endl;

  Vector4 vec4(1.0f, 2.0f, 3.0f, 4.0f);
  cout << "Vector4: " << vec4.toString() << " | Magnitud: " << vec4.length() << endl;

  cout << "\n==== PRUEBA DE QUATERNION ====" << endl;
  Quaternion q1 = Quaternion::fromAxisAngle(0, 1, 0, 90);
  q1.normalize();
  cout << "Quaternion (90° eje Y): " << q1.toString() << endl;

  cout << "\n==== PRUEBA DE MATRICES ====" << endl;
  Matrix2x2 mat2(2, 3, 1, 4);
  cout << "Matrix2x2:\n" << mat2.toString() << endl;
  cout << "Determinante: " << mat2.determinant() << endl;

  float m3vals[3][3] = {
    {1, 2, 3},
    {0, 1, 4},
    {5, 6, 0}
  };
  Matrix3x3 mat3(m3vals);
  cout << "\nMatrix3x3:\n" << mat3.toString();
  cout << "Determinante: " << mat3.determinant() << endl;

  Matrix4x4 mat4;
  cout << "\nMatrix4x4 identidad:\n" << mat4.toString();

  cout << "\n==== PRUEBA DE FUNCIONES MATEMÁTICAS (EngineMath) ====" << endl;

  cout << "Raíz de 25: " << sqrt(25.0f) << endl;
  cout << "3^2 (square): " << square(3.0f) << endl;
  cout << "2^3 (cube): " << cube(2.0f) << endl;
  cout << "5^4: " << power(5, 4) << endl;
  cout << "Abs(-8): " << absValue(-8.0f) << endl;
  cout << "Max(5, 8): " << eMax(5, 8) << " | Min(5, 8): " << eMin(5, 8) << endl;

  cout << "\nTrigonometría:\n";
  cout << "sin(30): " << sinValue(30.0f) << " | cos(60): " << cosValue(60.0f) << endl;

  cout << "\nÁreas y distancias:\n";
  cout << "Área círculo (r=5): " << circleArea(5.0f) << endl;
  cout << "Área rectángulo (4x8): " << rectangleArea(4.0f, 8.0f) << endl;
  cout << "Área triángulo (b=6, h=3): " << triangleArea(6.0f, 3.0f) << endl;
  cout << "Distancia (0,0) a (3,4): " << distance(0, 0, 3, 4) << endl;

  cout << "\nExtras:\n";
  cout << "Lerp entre 10 y 20 con t=0.5: " << lerp(10.0f, 20.0f, 0.5f) << endl;
  cout << "Factorial de 5: " << factorial(5) << endl;
  cout << "¿4.0001 ≈ 4.0? " << (approxEqual(4.0001f, 4.0f) ? "Sí" : "No") << endl;

  return 0;
}
