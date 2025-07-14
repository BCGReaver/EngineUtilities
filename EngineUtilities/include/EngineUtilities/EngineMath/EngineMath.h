#pragma once

#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

namespace EngineUtilities::EngineMath {

  // ==== FUNCIONES BÁSICAS ====

  float
    square(float value) {
    return value * value;
  }

  float
    cube(float value) {
    return value * value * value;
  }

  float
    power(float base, float exponent) {
    return pow(base, exponent);
  }

  float
    absValue(float value) {
    return fabs(value);
  }

  float
    eMax(float a, float b) {
    return max(a, b);
  }

  float
    eMin(float a, float b) {
    return min(a, b);
  }

  float
    roundValue(float value) {
    return round(value);
  }

  float
    floorValue(float value) {
    return floor(value);
  }

  float
    ceilValue(float value) {
    return ceil(value);
  }

  float
    modValue(float a, float b) {
    return fmod(a, b);
  }

  float
    expValue(float value) {
    return exp(value);
  }

  float
    logValue(float value) {
    return log(value);
  }

  float
    log10Value(float value) {
    return log10(value);
  }

  // ==== TRIGONOMETRÍA ====

  float
    sinValue(float degrees) {
    return sin(degrees * (3.14159265f / 180.0f));
  }

  float
    cosValue(float degrees) {
    return cos(degrees * (3.14159265f / 180.0f));
  }

  float
    tanValue(float degrees) {
    return tan(degrees * (3.14159265f / 180.0f));
  }

  float
    asinValue(float value) {
    return asin(value) * (180.0f / 3.14159265f);
  }

  float
    acosValue(float value) {
    return acos(value) * (180.0f / 3.14159265f);
  }

  float
    atanValue(float value) {
    return atan(value) * (180.0f / 3.14159265f);
  }

  float
    sinhValue(float value) {
    return sinh(value);
  }

  float
    coshValue(float value) {
    return cosh(value);
  }

  float
    tanhValue(float value) {
    return tanh(value);
  }

  // ==== CONVERSIÓN ANGULAR ====

  float
    radians(float degrees) {
    return degrees * (3.14159265f / 180.0f);
  }

  float
    degrees(float radians) {
    return radians * (180.0f / 3.14159265f);
  }

  // ==== FUNCIONES GEOMÉTRICAS ====

  float
    circleArea(float radius) {
    return 3.14159265f * radius * radius;
  }

  float
    circleCircumference(float radius) {
    return 2 * 3.14159265f * radius;
  }

  float
    rectangleArea(float width, float height) {
    return width * height;
  }

  float
    rectanglePerimeter(float width, float height) {
    return 2 * (width + height);
  }

  float
    triangleArea(float base, float height) {
    return 0.5f * base * height;
  }

  float
    distance(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
  }

  // ==== FUNCIONES VARIAS ====

  float
    lerp(float a, float b, float t) {
    return a + t * (b - a);
  }

  int
    factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
  }

  bool
    approxEqual(float a, float b, float tolerance = 0.0001f) {
    return fabs(a - b) <= tolerance;
  }

}

