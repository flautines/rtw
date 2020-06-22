#include <utils.h>
#include <limits>
#include <iostream>

namespace AMB
{
    
/////////////////////////////////////////////////////////////////////
//
vec3 random_in_unit_sphere()
{
   vec3 p;
   do
   {
      p = 2.0 * vec3 (drand48(), drand48(), drand48()) - vec3 (1,1,1);
   } while (p.squared_length() >= 1.0);

   return p;
}
/////////////////////////////////////////////////////////////////////
//
vec3 reflect (const vec3& v, const vec3& n)
{
   return v - 2 * dot (v,n)*n;
}

} // end of namespace AMB
