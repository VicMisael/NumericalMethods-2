#include "NumericalMethods.hpp"

double bisecction(double (*numFunc)(double), double a, double b, double E, int maxIter)
{
    double Fa = numFunc(a);
    double Fb = numFunc(b);
    if (Fa * Fb > 0)
    {
        std::cout << "Error, no sign change between a and b" << std::endl;
        return 0;
    }
    double interVx = fabs(b - a);
    int k = 0;
    double root = 0;
    while (interVx >= E && k <= maxIter)
    {
        double x = (a + b) / 2;
        double Fx = numFunc(x);

#ifdef PRINT_ITERATIONS
        std::cout << "K= " << k + 1 << " a= " << a << " Fa= " << Fa << "b= " << b << " x= " << x << " Fx= " << Fx << " intervX = " << interVx << std::endl;
#endif
        if (Fa * Fx > 0)
        {
            a = x;
            Fa = Fx;
        }
        else
        {
            b = x;
            Fb = Fx;
        }
        interVx = interVx / 2;
        k++;
        root = x;
    }
    return root;
}

double falsePosition(double (*numFunc)(double), double a, double b, double E1, double E2, int maxIter)
{
    double Fa = numFunc(a);
    double Fb = numFunc(b);
#ifdef PRINT_ITERATIONS
    std::cout << "E1= " << E1 << " E2= " << E2 << std::endl;
#endif
    if (Fa * Fb > 0)
    {
        std::cout << "Error, no sign change between a and b" << std::endl;
        return 0.0;
    }
    double interVx = fabs(b - a);
    double root = 0;
    if (interVx < E1)
    {
        root = (a + b) / 2;
    }
    if (fabs(Fa) < E2)
    {
        root = a;
    }
    if (fabs(Fb) < E2)
    {
        root = b;
    }
    int k = 0;
    while (true)
    {
        double x = (a * Fb - b * Fa) / (Fb - Fa);
        double Fx = numFunc(x);
#ifdef PRINT_ITERATIONS
        std::cout << "K= " << k + 1 << " a=" << a << " Fa=" << Fa << " b=" << b << " x=" << x << " Fx=" << Fx << " intervX=" << interVx << std::endl;
#endif
        if (fabs(Fx) < E2 || k >= maxIter)
        {
            root = x;
            break;
        }
        if (Fa * Fx > 0)
        {
            a = x;
            Fa = Fx;
        }
        else
        {
            b = x;
            Fb = Fx;
        }
        interVx = fabs(b - a);
        if (interVx <= E1)
        {
            root = (a + b) / 2;
            break;
        }

        ++k;
    }
    return root;
}

double newtonRaphson(double (*numFunc)(double), double (*derivative)(double), double x0, double E1, double E2, int maxIter)
{
    if (fabs(numFunc(x0)) < E1)
    {
        return x0;
    }
    int k = 1;
    double x1 = 0;
    while (true)
    {
        x1 = x0 - (numFunc(x0) / derivative(x0));
#ifdef PRINT_ITERATIONS
        std::cout << "K= " << k << " X0= " << x0 << " X1=" << x1 << " f(x0)=" << numFunc(x0) << " f(x1)" << numFunc(x1) << " derivative(x0)=" << derivative(x0) << std::endl;
#endif
        //Find a better way to implement this
        if (fabs(numFunc(x0)) < E1 || fabs(x1 - x0) < E2 || k >= maxIter)
        {
            return x1;
        }
        x0 = x1;
        k++;
    }
}

double secant(double (*numFunc)(double), double x0, double x1, double E1, double E2, int maxIter)
{
    if (fabs(numFunc(x0)) < E1)
    {
        return x0;
    }
    if (fabs(numFunc(x1)) < E1 || fabs(x1 - x0) < E2)
    {
        return x1;
    }
    int k = 1;
    double x2 = 0;
    while (true)
    {
        x2 = x1 - (numFunc(x1) / (numFunc(x1) - numFunc(x0))) * (x1 - x0);
#ifdef PRINT_ITERATIONS
        std::cout << "K= " << k << " X2=" << x1 << " f(x1)" << numFunc(x2) << std::endl;
#endif
        //Find a better way to implement this
        if (fabs(numFunc(x2)) < E1 || fabs(x2 - x1) < E2 || k >= maxIter)
        {
            return x2;
        }
        x0 = x1;
        x1 = x2;
        k++;
    }
}
double fixedPoint(double (*numFunc)(double), double (*phi)(double), double x0, double E1, double E2, int maxIter)
{
    if (fabs(numFunc(x0)) < E1)
    {
        std::cout << "saiu";
        return x0;
    }
    int k = 1;
    double x1 = 0;
    while (true)
    {
        x1 = phi(x0);
#ifdef PRINT_ITERATIONS
        std::cout << "K= " << k << " X0= " << x0 << " X1=" << x1 << " f(x0)=" << numFunc(x0) << " phi(x1)=" << phi(x1) << std::endl;
#endif
        //Find a better way to implement this
        if (fabs(numFunc(x0)) < E1 || fabs(x1 - x0) < E2 || k >= maxIter)
        {
            return x1;
        }
        x0 = x1;
        k++;
    }
}
double polynomials(int n, double a[], double x, double E1, double E2, int maxIter)
{
    double deltax = x;
    for (int k = 1; k <= maxIter; k++)
    {
        double b = a[n];
        double c = b;
        for (int i = (n - 1); i >= 1; i--)
        {
            b = a[i] + b * x;
            c = b + c * x;
        }
        b = a[0] + b * x;
        if (fabs(b) < E1)
        {
            return x;
        }
        deltax = b / c;
        x = x - deltax;
        if (fabs(deltax) < E2)
        {
            return x;
        }
    }
#ifdef PRINT_ITERATIONS
    std::cout << "Didn't Coverge after " << maxIter << "Times" << std::endl;
#endif
    return x;
}