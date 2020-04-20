#include <iostream>
#include <fstream>

#include "vec3.h"
#include "ray.h"

int main() {
    const int image_width = 200;
    const int image_height = 100;

    std::ofstream myfile;
    myfile.open("test.ppm");

    myfile << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            vec3 color(double(i) / image_width, double(j) / image_height, 0.2);
            color.write_color(myfile);
        }
    }
    std::cerr << "\nDone.\n";
    myfile.close();
}