#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <sphere.h>
#include <hitablelist.h>
#include <camera.h>
#include <material.h>
using namespace AMB;
/////////////////////////////////////////////////////////////////////
//
vec3 color (const ray& r, const hitable& world, int depth)
{
   hit_record rec;

   if (depth <= 0)
      return vec3 (0,0,0);

   if (world.hit (r, 0.001, std::numeric_limits<float>::max(), rec))
   {
      ray scattered;
      vec3 attenuation;
      if (rec.mat_ptr->scatter (r, rec, attenuation, scattered))
      {
         return attenuation * color (scattered, world, depth-1);
      }
      return vec3 (0,0,0);      
   }

   vec3 unit_dir = unit_vector (r.direction());
   float t = 0.5 * (unit_dir.y() + 1.0);
   return (1.0-t) * vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0);   
}
/////////////////////////////////////////////////////////////////////
//
int main(int argc, char* argv[]) 
{
   //int nx = 200;
   //int ny = 100;
   int nx = 1024;
   int ny = 576;
   int ns = 20;
   const int max_depth = 50;

   if (argc > 1)
      ns = std::stoi (argv[1]);

   std::clog << "Using " << ns << " samples/pixel\n";
   std::cout << "P3\n" << nx << " " << ny << "\n255\n";   

   hitable_list world;
   world.add (make_shared<sphere>(
      vec3 (0,0,-1), 0.5, make_shared<lambertian>(vec3 (0.7, 0.3, 0.3))));

   world.add (make_shared<sphere>(
      vec3 (0,-100.5,-1), 100, make_shared<lambertian>(vec3 (0.8, 0.8, 0.0))));

   world.add (make_shared<sphere>(
      vec3 (1,0,-1), 0.5, make_shared<metal>(vec3(0.8, 0.6, 0.2), 0.3)));

   world.add (make_shared<sphere>(
      vec3 (-1,0,-1), 0.5, make_shared<metal>(vec3(0.8, 0.8, 0.8), 1.0)));

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
            col += color (r, world, max_depth);
            offset_u = drand48();
            offset_v = drand48();
         }
         col /= float (ns);

         // Corrección gamma 2.0 (col = pow(1/gamma) = pow(1/2) = sqrt())
         col = vec3 (sqrt (col.r()), sqrt (col.g()), sqrt (col.b()));
         int ir = int (255.99*col.r());
         int ig = int (255.99*col.g());
         int ib = int (255.99*col.b());

         std::cout << ir << " " << ig << " " << ib << "\n";   
      }      
   }
}