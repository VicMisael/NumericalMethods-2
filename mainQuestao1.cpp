#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "NumericalMethods.hpp"

 double expression1( double x)
{
    return -(exp(x) / 2) + 2 * cos(x);
}

int main(int argc, char *argv[])
{
    std::cout << "Bisecção" << std::endl;
    std::cout << bisecction(&expression1, (M_PI) /(double) 4, (M_PI) /(double) 3, 0.0001, 105) << std::endl;
    std::cout << "Ponto Falso" << std::endl;
    std::cout << falsePosition(&expression1, (M_PI) / 4, (M_PI) / 3, 0.0001,0.0001, 105) << std::endl;


}