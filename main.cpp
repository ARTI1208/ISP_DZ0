#include <iostream>
#include <vector>
#include <cmath>

bool isZero(double value)
{
    return std::abs(value) < 1e-10;
}

// bx + c = 0
int solveLinearEq(double b, double c, double& res)
{
    if (isZero(b)) return -1;
    res = -c / b;
    return 0;
}

void solveQuadraticEq(double a, double b, double c, std::vector<double>& res)
{
    if (iszero(a))
    {
        double answer;
        if (solveLinearEq(b, c, answer) == 0)
        {
            res.push_back(answer);
        }
        return;
    }

    // x(ax + b) = 0
    if (iszero(c))
    {
        res.push_back(0);
        double secondAnswer;
        if (!isZero(b) && solveLinearEq(a, b, secondAnswer) == 0)
        {
            res.push_back(secondAnswer);
        }
        return;
    }

    double disc = b * b - 4 * a * c;
    if (disc < 0) return;
    if (isZero(disc))
    {
        res.push_back(b / (2 * a));
    }
    else
    {
        double discSqrt = std::sqrt(disc);
        res.push_back((b - discSqrt) / (2 * a)); //x1
        res.push_back((b + discSqrt) / (2 * a)); //x2
    }
}


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

    std::vector<double> res;

    for (auto q : eqs)
    {
        res.clear();

        solveQuadraticEq(q.a, q.b, q.c, res);

        printf("Solve of %fx^2 + %fx + %f = 0:\n", q.a, q.b, q.c);

        switch (res.size())
        {
            case 0:
                printf("No solve\n");
                break;
            case 1:
                printf("x = %f\n", res[0]);
                break;
            default:
                for (int i = 0; i < res.size(); ++i)
                {
                    printf("x%d = %f\n", i + 1, res[i]);
                }
                break;
        }
        printf("\n");
    }

    return 0;
}
