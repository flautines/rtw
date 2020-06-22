#pragma once

#include <ray.h>
#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

//#include <material.h>
namespace AMB
{

// forward declaration, defined in material.h
class material;

struct hit_record
{
    float     t;
    vec3      p;
    vec3      normal;
    shared_ptr<material> mat_ptr;
};

class hitable
{
public:
    virtual bool hit (const ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};

} // end of namespace AMB
