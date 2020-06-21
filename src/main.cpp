#include <iostream>
#include <limits>
#include <cstdlib>
#include <string>
#include <math.h>
#include <sphere.h>
#include <hitablelist.h>
#include <camera.h>
using namespace AMB;

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
vec3 color (const ray& r, hitable* world)
{
   hit_record rec;
   if (world->hit (r, 0.001, std::numeric_limits<float>::max(), rec))
   {
      vec3 target = rec.p + rec.normal + random_in_unit_sphere();
      return 0.5 * color (ray (rec.p, target - rec.p), world);
   }
   else 
   {
      vec3 unit_dir = unit_vector (r.direction());
      float t = 0.5 * (unit_dir.y() + 1.0);
      return (1.0-t) * vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0);   
   }   
}
/////////////////////////////////////////////////////////////////////
//
int main(int argc, char* argv[]) 
{
   int nx = 200;
   int ny = 100;
   int ns = 1;

   if (argc > 1)
      ns = std::stoi (argv[1]);

   std::clog << "Using " << ns << " samples/pixel\n";
   std::cout << "P3\n" << nx << " " << ny << "\n255\n";   

   hitable *list[2];
   list[0] = new sphere (vec3 (0,0,-1), 0.5);
   list[1] = new sphere (vec3 (0,-100.5,-1), 100);
   hitable* world = new hitable_list (list, 2);

   camera cam;
   float offset_u = 0.0;
   float offset_v = 0.0;
   for (int j = ny-1; j >= 0; j--)
   {
      for (int i = 0; i < nx; i++)
      {
         vec3 col(0,0,0);
         // for each pixel send 'ns' sample rays
         for (int s = 0; s < ns; s++)
         {
            float u = float (i + offset_u) / float (nx);
            float v = float (j + offset_v) / float (ny);
            ray r = cam.get_ray (u, v);
            //vec3   p = r.point_at_parameter (2.0);
            col += color (r, world);
            offset_u = drand48();
            offset_v = drand48();
         }
         col /= float (ns);

         // Corrección gamma 2.0 (col = pow(1/gamma) = pow(1/2) = sqrt())
         //col = vec3 (sqrt (col.r()), sqrt (col.g()), sqrt (col.b()));
         int ir = int (255.99*col.r());
         int ig = int (255.99*col.g());
         int ib = int (255.99*col.b());

         std::cout << ir << " " << ig << " " << ib << "\n";   
      }      
   }
}