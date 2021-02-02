#include <cmath>
#include <iostream>
#define PRINT_ITERATIONS

 double bisecction( double (*numFunc)( double), double a, double b, double E, int maxIter);
 double falsePosition( double (*numFunc)( double), double a, double b, double E1, double E2, int maxIter);
 double newtonRaphson( double (*numFunc)( double),  double (*derivative)( double), double x0, double E1, double E2, int maxIter);
 double secant( double (*numFunc)( double), double x0, double x1, double E1, double E2, int maxIter);
 double fixedPoint(double (*numFunc)(double), double (*phi)(double), double x0, double E1, double E2, int maxIter);
 double polynomials(int n, double a[], double x, double E1, double E2, int maxIter);