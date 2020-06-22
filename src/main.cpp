#include <color.h>
#include <iostream>

int main()
{
    const int image_width = 256;
    const int image_height = 256;

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\r\033[37;1mScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            AMB::color pixel_color(double(i)/(image_width-1), 
                              double(j)/(image_height-1),
                              0.25);
            AMB::write_color(std::cout, pixel_color);
        }
    }
    std::cerr << "\n\033[32;1mDone.\033[0m\n";
}
