#pragma once

#include <hitable.h>
#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

namespace AMB
{

class sphere: public hitable
{
public:
    sphere();
    sphere(vec3 c, float r, shared_ptr<material> m);
    bool hit (const ray& r, float tmin, float tmax, hit_record& rec) const override;
private:
    vec3      _center;
    float     _radius;
    shared_ptr<material> _mat_ptr;
};

} // end of namespace AMB