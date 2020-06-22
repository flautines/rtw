#pragma once

#include <ray.h>
#include <vec3.h>

namespace AMB
{

struct hit_record;

class material
{
public:
    virtual bool scatter (
        const ray&        r_in, 
        const hit_record& rec, 
              vec3&       attenuation,
              ray&        scattered
    ) const = 0;
};

class lambertian: public material
{
public:
    lambertian(const vec3& a);
    virtual bool scatter (
        const   ray&        r_in, 
        const   hit_record& rec, 
                vec3&       attenuation,
                ray&        scattered
    ) const override;
private:
    vec3 _albedo;
};    

class metal: public material
{
public:
    metal(const vec3& a, float f);
    virtual bool scatter (
        const   ray&        r_in, 
        const   hit_record& rec, 
                vec3&       attenuation,
                ray&        scattered
    ) const override;
private:
    vec3  _albedo;
    float _fuzz;
};    

}
