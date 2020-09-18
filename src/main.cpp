#include <iostream>
#include <vector>
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

    for (auto q : eqs)
    {
        double res1 = NAN;
        double res2 = NAN;

        int rootCount = solveQuadraticEquation(q.a, q.b, q.c, res1, res2);

        printf("Solve of %fx^2 + %fx + %f = 0:\n", q.a, q.b, q.c);

        switch (rootCount)
        {
            case 0:
                printf("No solve\n");
                break;
            case 1:
                printf("x = %f\n", res1);
                break;
            case 2:
                printf("x1 = %f\n", res1);
                printf("x2 = %f\n", res2);
                break;
            case INFINITE_ROOTS_COUNT:
                printf("Every number is a solution\n");
                break;
            default:
                printf("That should never happen, but we have %d roots", rootCount);
                break;
        }
        printf("\n");
    }

    return 0;
}
