#include <color.h>

namespace AMB
{

void write_color(std::ostream& os, color pixel_color)
{
    // Write the translated [0,255] value of each color componenet.
    os << static_cast<int>(255.999 * pixel_color.x()) << ' '
       << static_cast<int>(255.999 * pixel_color.y()) << ' '
       << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

} // end of namespace AMB
