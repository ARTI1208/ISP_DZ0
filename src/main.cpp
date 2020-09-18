#include <iostream>
#include <vector>
#include "tests.h"
#include <cmath>
#include "equations.h"


class QuadraticEq
{

public:

    double a, b, c;

    explicit QuadraticEq(double a = 0.0, double b = 0.0, double c = 0.0) : a(a), b(b), c(c)
    {}

};

int main()
{
    std::vector<QuadraticEq> eqs = {
            QuadraticEq(),
            QuadraticEq(1),
            QuadraticEq(1, 2),
            QuadraticEq(1, 2, 3),
    };

    runAllTests();

    return 0;
}
