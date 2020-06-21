#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <vec3.h>

namespace AMB {

vec3::vec3()
{

}
vec3::vec3(float e0, float e1, float e2) :
   _e { e0, e1, e2 } {}

float  vec3::x() const
{
   return _e[0];
}

float  vec3::y() const
{
   return _e[1];
}

float  vec3::z() const
{
   return _e[2];
}

float  vec3::r() const
{
   return _e[0];
}

float  vec3::g() const
{
   return _e[1];
}

float  vec3::b() const
{
   return _e[2];
}

const vec3&  vec3::operator+ () const
{
   return *this;
}

vec3 vec3::operator- () const
{
   return vec3(-_e[0], -_e[1], -_e[2]);
}

float vec3::operator[](int i) const
{
   return _e[i];
}

float& vec3::operator[](int i)
{
   return _e[i];
}

vec3&  vec3::operator+=(const vec3& v)
{
   _e[0] += v[0];
   _e[1] += v[1];
   _e[2] += v[2];
   return *this;
}

vec3&  vec3::operator-=(const vec3& v)
{
   _e[0] -= v[0];
   _e[1] -= v[1];
   _e[2] -= v[2];
   return *this;
}

vec3&  vec3::operator*=(const vec3& v)
{
   _e[0] *= v[0];
   _e[1] *= v[1];
   _e[2] *= v[2];
   return *this;
}

vec3&  vec3::operator/=(const vec3& v)
{
   _e[0] /= v[0];
   _e[1] /= v[1];
   _e[2] /= v[2];
   return *this;
}

vec3&  vec3::operator*=(const float k)
{
   _e[0] += k;
   _e[1] += k;
   _e[2] += k;
   return *this;
}

vec3&  vec3::operator/=(const float k)
{
   _e[0] /= k;
   _e[1] /= k;
   _e[2] /= k;
   return *this;
}

float vec3::length() const
{
   return sqrt(_e[0]*_e[0] + _e[1]*_e[1] + _e[2]*_e[2]);
}

float vec3::squared_length() const
{
   return (_e[0]*_e[0] + _e[1]*_e[1] + _e[2]*_e[2]);
}

void vec3::make_unit_vector()
{
   float k = 1.0 / length();
   _e[0] *= k;
   _e[1] *= k;
   _e[2] *= k;
}

vec3 unit_vector(vec3 v)
{
   return v / v.length();
}

std::istream& operator>>(std::istream& is, vec3& t)
{
   is >> t._e[0] >> t._e[1] >> t._e[2];
   return is;
}

std::ostream& operator<<(std::ostream& os, const vec3& t)
{
   os << t._e[0] << " " << t._e[1] << " " << t._e[2];
   return os;
}

vec3 operator+(const vec3& v1, const vec3& v2)
{
   return vec3(v1._e[0] + v2._e[0],
               v1._e[1] + v2._e[1],
               v1._e[2] + v2._e[2]);
}

vec3 operator-(const vec3& v1, const vec3& v2)
{
   return vec3(v1._e[0] - v2._e[0],
               v1._e[1] - v2._e[1],
               v1._e[2] - v2._e[2]);
}

vec3 operator*(const vec3& v1, const vec3& v2)
{
   return vec3(v1._e[0] * v2._e[0],
               v1._e[1] * v2._e[1],
               v1._e[2] * v2._e[2]);
}

vec3 operator/(const vec3& v1, const vec3& v2)
{
   return vec3(v1._e[0] / v2._e[0],
               v1._e[1] / v2._e[1],
               v1._e[2] / v2._e[2]);
}

vec3 operator*(float k, const vec3& v)
{
   return vec3(k * v._e[0],
               k * v._e[1],
               k * v._e[2]);
}

vec3 operator*(const vec3& v, float k)
{
   return k*v;
}

vec3 operator/(const vec3& v, float k)
{
   return vec3(v._e[0] / k,
               v._e[1] / k,
               v._e[2] / k);
}

float dot(const vec3& v1, const vec3& v2)
{
   return v1._e[0] * v2._e[0] +
          v1._e[1] * v2._e[1] +
          v1._e[2] * v2._e[2];
}

vec3 cross(const vec3& v1, const vec3& v2)
{
   return vec3( 
      (v1._e[1] * v2._e[2] - v1._e[2] * v2._e[1]),
      (v1._e[2] * v2._e[0] - v1._e[0] * v2._e[2]),
      (v1._e[0] * v2._e[1] - v1._e[1] * v2._e[0])
   );
}


}; // end of AMB Namespace