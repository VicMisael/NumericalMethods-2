#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "NumericalMethods.hpp"

double p3(double x)
{
    return pow(x, 3) - (9 * x) + 3;
}
double p3Phi(double x)
{

    return powf(x, 3) / 9 + ((double)1 / 3);
}

int main(int argc, char *argv[])
{
    std::cout << "FixedPoint" << std::endl;
    std::cout << fixedPoint(p3, p3Phi, 0, 0.00001, 0.00001, 15) << std::endl;
    std::cout << "Polinomios" << std::endl;
    double an[] = {3, -9, 0, 1};
    std::cout << polynomials(3, an, 0, 0.00001, 0.00001, 1000) << std::endl;
    ;
}