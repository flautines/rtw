#include <camera.h>

namespace AMB 
{

camera::camera() :
    _lower_left_corner { -2.0, -1.0, -1.0 },
    _horizontal { 4.0, 0.0, 0.0 },
    _vertical { 0.0, 2.0, 0.0 },
    _origin { 0.0, 0.0, 0.0 }
{

}

ray camera::get_ray (float u, float v)
{
    return ray (_origin, _lower_left_corner + u*_horizontal + v*_vertical - _origin);
}

}