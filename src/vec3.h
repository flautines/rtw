#pragma once

#include <iostream>

namespace AMB {
class vec3 
{
public:
	  	     vec3();
	  	     vec3(float e0, float e1, float e2);
	  float  x() const;
	  float  y() const;
	  float  z() const;
	  float  r() const;
	  float  g() const;
	  float  b() const;

const vec3&  operator+ () 	   const;
	  vec3 	 operator- () 	   const;
	  float  operator[](int i) const;
	  float& operator[](int i)      ;

	  vec3&  operator+=(const vec3& v);
	  vec3&  operator-=(const vec3& v);
	  vec3&  operator*=(const vec3& v);
	  vec3&  operator/=(const vec3& v);
	  vec3&  operator*=(const float k);
	  vec3&  operator/=(const float k);

	  float  length() 		  const;
	  float  squared_length() const;
	  void	 make_unit_vector();
friend std::istream& operator>>(std::istream& is, vec3& t);
friend std::ostream& operator<<(std::ostream& os, const vec3& t);
friend vec3 operator+(const vec3& v1, const vec3& v2);
friend vec3 operator-(const vec3& v1, const vec3& v2);
friend vec3 operator*(const vec3& v1, const vec3& v2);
friend vec3 operator/(const vec3& v1, const vec3& v2);
friend vec3 operator*(float k, const vec3& v);
friend vec3 operator*(const vec3& v, float k);
friend vec3 operator/(const vec3& v, float k);
friend float dot(const vec3& v1, const vec3& v2);
friend vec3 cross(const vec3& v1, const vec3& v2);
friend vec3 unit_vector(vec3 v);

private:
	float _e[3];
}; // end of vec3 class

std::istream& operator>>(std::istream& is, vec3& t);
std::ostream& operator<<(std::ostream& os, const vec3& t);
vec3 operator+(const vec3& v1, const vec3& v2);
vec3 operator-(const vec3& v1, const vec3& v2);
vec3 operator*(const vec3& v1, const vec3& v2);
vec3 operator/(const vec3& v1, const vec3& v2);
vec3 operator*(float k, const vec3& v);
vec3 operator*(const vec3& v, float k);
vec3 operator/(const vec3& v, float k);
float dot(const vec3& v1, const vec3& v2);
vec3 cross(const vec3& v1, const vec3& v2);
vec3 unit_vector(vec3 v);
}; // end of AMB Namespace
