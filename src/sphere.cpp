#include <math.h>
#include <sphere.h>

namespace AMB
{

sphere::sphere()
{

}

sphere::sphere(vec3 c, float r) :
    _center { c }, _radius { r }
{

}

bool sphere::hit (const ray& r, float t_min, float t_max, hit_record& rec) const
{
    vec3 oc = r.origin() - _center;
    float a = dot (r.direction(), r.direction());
    float b = dot (oc, r.direction());
    float c = dot (oc, oc) - _radius * _radius;
    float discriminant = b*b - a*c;

    if (discriminant > 0)
    {
        float t = (-b - sqrt (b*b - a*c)) / a;
        if (t < t_max && t > t_min)
        {
            rec.t = t;
            rec.p = r.point_at_parameter (rec.t);
            rec.normal = (rec.p - _center) / _radius;
            return true;
        }
        t = (-b + sqrt (b*b - a*c)) / a;
        if (t < t_max && t > t_min)
        {
            rec.t = t;
            rec.p = r.point_at_parameter (rec.t);
            rec.normal = (rec.p - _center) / _radius;
            return true;
        }
    }
    return false;
}

}
