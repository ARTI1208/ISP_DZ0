//
// Created by arti1208 on 18.09.2020.
//

#include <cassert>
#include <cmath>
#include "equations.h"

bool isZero(double value) {
    return std::abs(value) < EPSILON;
}

// ax + b = 0
int solveLinearEquation(double a, double b, double& res) {
    assert(std::isfinite(a));
    assert(std::isfinite(b));

    if (!(std::isfinite(a) && std::isfinite(b))) return EVALUATION_ERROR;

    if (a < 1) {
        double multiplier = 1 / EPSILON;
        a *= multiplier;
        b *= multiplier;
    }

    if (isZero(a)) {
        if (isZero(b)) return INFINITE_ROOTS_COUNT;
        return 0;
    }
    res = -b / a;
    return 1;
}

int solveQuadraticEquation(double a, double b, double c, double& res1, double& res2) {
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));

    if (!(std::isfinite(a) && std::isfinite(b) && std::isfinite(c))) return EVALUATION_ERROR;

    if (a < 1) {
        double multiplier = 1 / EPSILON;
        a *= multiplier;
        b *= multiplier;
        c *= multiplier;
    }

    if (isZero(a)) {
        return solveLinearEquation(b, c, res1);
    }

    // x(ax + b) = 0
    if (isZero(c)) {
        res1 = 0;

        // Calculate result for part in brackets and add one certain root - zero.
        // We can't get INFINITE_ROOTS_COUNT here as this case is checked before (first if)
        // isZero check so we won't put another zero value to res2 when res1 already has it
        return isZero(b) ? 1 : solveLinearEquation(a, b, res2) + 1;
    }

    double disc = discriminant(a, b, c);
    if (!std::isfinite(disc)) return EVALUATION_ERROR;
    if (disc < 0) return 0;

    if (isZero(disc)) {
        res1 = -b / (2 * a);
        return 1;
    } else {
        double discSqrt = std::sqrt(disc);
        res1 = (-b - discSqrt) / (2 * a);
        res2 = (-b + discSqrt) / (2 * a);
        return 2;
    }
}

double discriminant(double a, double b, double c) {
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));

    return b * b - 4 * a * c;
}