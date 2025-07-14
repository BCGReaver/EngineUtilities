#include <iostream>
#include "../include/Vectors/Vector2.h"
#include "../include/Vectors/Vector3.h"
#include "../include/Vectors/Vector4.h"
#include "../include/Rotations/Quaternion.h"
#include "../include/Matrices/Matrix2x2.h"
#include "../include/Matrices/Matrix3x3.h"
#include "../include/Matrices/Matrix4x4.h"
#include "../include/EngineMath/EngineMath.h"
#include "../include/ECS/Entity.h"
#include "../include/ECS/Component.h"
#include "../include/ECS/System.h"

using namespace std;
using namespace EngineUtilities::Vectors;
using namespace EngineUtilities::Rotations;
using namespace EngineUtilities::Matrices;
using namespace EngineUtilities::EngineMath;
using namespace EngineUtilities::ECS;

int
main() {
  cout << "Disculpara las faltas de ortografia pero el vs no jala chido pa eso" << endl;
  cout << "\n";
  cout << "\tPruebas" << endl;
  cout << "\n";
  Vector2 vec2(3.0f, 4.0f);
  cout << "Vector2: " << vec2.toString() << " | Magnitud: " << vec2.length() << endl;

  Vector3 vec3(1.0f, 2.0f, 2.0f);
  cout << "Vector3: " << vec3.toString() << " | Magnitud: " << vec3.length() << endl;

  Vector4 vec4(1.0f, 2.0f, 3.0f, 4.0f);
  cout << "Vector4: " << vec4.toString() << " | Magnitud: " << vec4.length() << endl;

  cout << "\n";
  cout << "\tQuaternion" << endl;
  cout << "\n";
  Quaternion q1 = Quaternion::fromAxisAngle(0, 1, 0, 90);
  q1.normalize();
  cout << "Quaternion (90° eje Y): " << q1.toString() << endl;

  cout << "\n";
  cout << "\tMatrices" << endl;
  cout << "\n";
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

  cout << "\n";
  cout << "\tFunciones matematicas" << endl;
  cout << "\n";

  cout << "Raiz de 25: " << sqrt(25.0f) << endl;
  cout << "3^2 (square): " << square(3.0f) << endl;
  cout << "2^3 (cube): " << cube(2.0f) << endl;
  cout << "5^4: " << power(5, 4) << endl;
  cout << "Abs(-8): " << absValue(-8.0f) << endl;
  cout << "Max(5, 8): " << eMax(5, 8) << " | Min(5, 8): " << eMin(5, 8) << endl;

  cout << "\nTrigonometria:\n";
  cout << "sin(30): " << sinValue(30.0f) << " | cos(60): " << cosValue(60.0f) << endl;

  cout << "\nAreas y distancias:\n";
  cout << "Area circulo (r=5): " << circleArea(5.0f) << endl;
  cout << "Area rectangulo (4x8): " << rectangleArea(4.0f, 8.0f) << endl;
  cout << "Area triangulo (b=6, h=3): " << triangleArea(6.0f, 3.0f) << endl;
  cout << "Distancia (0,0) a (3,4): " << distance(0, 0, 3, 4) << endl;

  cout << "\nExtras:\n";
  cout << "Lerp entre 10 y 20 con t=0.5: " << lerp(10.0f, 20.0f, 0.5f) << endl;
  cout << "Factorial de 5: " << factorial(5) << endl;
  cout << "4.0001 ≈ 4.0 " << (approxEqual(4.0001f, 4.0f) ? "Sí" : "No") << endl;

  cout << "\n";
  cout << "\tECS" << endl;
  cout << "\n";
  System testSystem;
  testSystem.update();

  return 0;
}