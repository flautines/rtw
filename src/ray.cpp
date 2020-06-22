#include <ray.h>

namespace AMB 
{
ray::ray()
{

}

ray::ray(const vec3& origin, const vec3& dir) :
    _origin { origin }, _direction { dir }
{

}

vec3 ray::origin() const
{
    return _origin;
}

vec3 ray::direction() const
{
    return _direction;
}

vec3 ray::at (float t) const    
{
    return _origin + t * _direction;
}

} // end of namespace AMB
