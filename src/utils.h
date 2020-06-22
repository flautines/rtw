#pragma once

#include <ray.h>
#include <hitable.h>

namespace AMB
{

vec3 random_in_unit_sphere();    
vec3 color (const ray& r, const hitable& world, int depth);
vec3 reflect (const vec3& v, const vec3& n);

} // end of namespace AMB
