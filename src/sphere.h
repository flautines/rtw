#pragma once

#include <hitable.h>

namespace AMB
{

class sphere: public hitable
{
public:
    sphere();
    sphere(vec3 c, float r);
    bool hit (const ray& r, float tmin, float tmax, hit_record& rec) const override;
private:
    vec3 _center;
    float _radius;
};

} // end of namespace AMB