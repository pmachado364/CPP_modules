#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);
    std::cout << "Defining a triangle with points A(0, 0), B(10, 0), and C(0, 10)" << std::endl;
    Point i(2, 2);
    Point o(20, 20);
    Point e(5, 0);

    if (bsp(a, b, c, i))
        std::cout << "Point i(2, 2) is inside the triangle." << std::endl;
    else
        std::cout << "Point i(2, 2) is outside the triangle." << std::endl;

    if (bsp(a, b, c, o))
        std::cout << "Point o(20, 20) is inside the triangle." << std::endl;
    else
        std::cout << "Point o(20, 20) is outside the triangle." << std::endl;

    if (bsp(a, b, c, e))
        std::cout << "Point e(5, 0) is inside the triangle." << std::endl;
    else
        std::cout << "Point e(5, 0) is outside the triangle." << std::endl;

    return 0;
}
