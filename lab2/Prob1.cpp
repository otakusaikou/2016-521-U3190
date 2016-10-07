#include <iostream>
#include <cmath>
#include "Prob1.h"

int main()
{
    // Initialize the triangle object
    Triangle Tri;

    // Catch the user input
    std::cout << "Please input the x & y coordinates of the 1st vertex" << std::endl;
    std::cin >> Tri.A.x >> Tri.A.y;

    std::cout << "Please input the x & y coordinates of the 2st vertex" << std::endl;
    std::cin >> Tri.B.x >> Tri.B.y;

    std::cout << "Please input the x & y coordinates of the 3st vertex" << std::endl;
    std::cin >> Tri.C.x >> Tri.C.y;

    // Compute length of all edges
    double AB = std::hypot((Tri.B.x - Tri.A.x), (Tri.B.y - Tri.A.y));
    double BC = std::hypot((Tri.C.x - Tri.B.x), (Tri.C.y - Tri.B.y));
    double CA = std::hypot((Tri.A.x - Tri.C.x), (Tri.A.y - Tri.C.y));

    // Ensure that all the edge are not equal to zero
    if (AB == 0 || BC == 0 || CA == 0) {
        std::cout << "This is not a right triangle!" << std::endl;
        return -1;
    }

    // Verify the right triangle
    if (BC == std::hypot(CA, AB)) {
        std::cout << "This is a right triangle!\nThe right angle is at the Vertex 1" << std::endl;
    } else if (CA == std::hypot(AB, BC)) {
        std::cout << "This is a right triangle!\nThe right angle is at the Vertex 2" << std::endl;
    } else if (AB == std::hypot(BC, CA)) {
        std::cout << "This is a right triangle!\nThe right angle is at the Vertex 3" << std::endl;
    } else {
        std::cout << "This is not a right triangle!" << std::endl;
    }

    return 0;
}
