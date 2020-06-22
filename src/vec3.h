#pragma once

#include <iostream>

namespace AMB {

class vec3 {
public:
    vec3();
    vec3(double e0, double e1, double e2);

    double x() const;
    double y() const;
    double z() const;

    vec3 operator-() const;
    double operator[](int i) const;
    double& operator[](int i);

    vec3& operator+=(const vec3& v);
    vec3& operator*=(const double t);
    vec3& operator/=(const double t);

    double length() const;
    double length_squared() const;

friend std::ostream& operator<<(std::ostream& o, const vec3& v);
friend vec3 operator+(const vec3& u, const vec3& v);
friend vec3 operator-(const vec3& u, const vec3& v);
friend vec3 operator*(const vec3& u, const vec3& v);
friend vec3 operator*(double t, const vec3& v);
friend vec3 operator*(const vec3& v, double t);
friend vec3 operator/(vec3& u, double t);

friend double dot(const vec3& u, const vec3&);
friend vec3 cross(const vec3& u, const vec3& v);
friend vec3 unit_vector(vec3 v);

private:
    double e[3];
};

std::ostream& operator<<(std::ostream& os, const vec3& v);
vec3 operator+(const vec3& u, const vec3& v);
vec3 operator-(const vec3& u, const vec3& v);
vec3 operator*(const vec3& u, const vec3& v);
vec3 operator*(double t, const vec3& v);
vec3 operator*(const vec3& v, double t);
vec3 operator/(vec3& u, double t);

double dot(const vec3& u, const vec3&);
vec3 cross(const vec3& u, const vec3& v);
vec3 unit_vector(vec3 v);

// type aliases for vec3
using point3 = vec3;    // 3D point
using color  = vec3;    // RGB color

} // end of namespace AMB