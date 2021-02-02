#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "NumericalMethods.hpp"

double func(double x)
{
    return x - x * logf((x));
}
double funcDerivative(double x)
{
    return -logf(x);
}
double funcPhi(double x)
{
    return x / logf((x));
}

int main(int argc, char *argv[])
{
    std::cout << "Newton Raphson" << std::endl;
    double value =3/ (double)2;
    std::cout << newtonRaphson(func, funcDerivative, value, 0.000001, 0.000001, 15) << std::endl;
    std::cout << "Fixed Point" << std::endl;
    std::cout << fixedPoint(func, funcPhi, value, 0.000001, 0.000001, 15) << std::endl;
}