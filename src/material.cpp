#include <material.h>
#include <utils.h>

namespace AMB
{
    
lambertian::lambertian(const vec3& a) :
    _albedo { a }
{

}

bool lambertian::scatter (
    const ray&        r_in, 
    const hit_record& rec, 
          vec3&       attenuation,
          ray&        scattered) const
{
    vec3 scatter_direction = rec.normal + random_in_unit_sphere();
    scattered = ray (rec.p, scatter_direction);
    attenuation = _albedo;
    return true;
}

metal::metal(const vec3& a, float f) :
    _albedo { a }, _fuzz ( f < 1 ? f : 1)
{

}

bool metal::scatter (
    const ray&        r_in, 
    const hit_record& rec, 
          vec3&       attenuation,
          ray&        scattered) const
{
    vec3 reflected = reflect (unit_vector (r_in.direction()), rec.normal);
    scattered = ray (rec.p, reflected + _fuzz*random_in_unit_sphere());
    attenuation = _albedo;
    return (dot (scattered.direction(), rec.normal) > 0);
}

} // end of namespace AMB