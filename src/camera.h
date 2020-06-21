#pragma once

#include <ray.h>

namespace AMB
{

class camera
{
public:
    camera();
    ray get_ray (float u, float v);
private:    
    vec3 _lower_left_corner;
    vec3 _horizontal;
    vec3 _vertical;
    vec3 _origin;
};

} // end of namespace AMB
