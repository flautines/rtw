#pragma once

#include <vec3.h>

namespace AMB
{

class ray
{
public:
    ray();
    ray(const vec3& origin, const vec3& dir);
    vec3 origin() const;
    vec3 direction() const;
    vec3 point_at_parameter (float t) const;

private:
    vec3 _origin;
    vec3 _direction;
};

} // end of namespace AMB

