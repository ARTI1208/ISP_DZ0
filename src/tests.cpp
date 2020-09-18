//
// Created by arti1208 on 18.09.2020.
//

#include <string>
#include <cmath>
#include <iostream>
#include "tests.h"
#include "equations.h"

static const char* boolToString(bool value) {
    return value ? "true" : "false";
}

static void test(bool actual, bool expected, const char* testName) {
    std::cout << testName << ": ";
    if (actual == expected) {
        std::cout << "PASSED";
    } else {
        std::cout << "FAILED. Expected " << boolToString(expected) << ", but got " << boolToString(actual);
    }
    std::cout << "\n";
}

static void test(int actual, int expected, const char* testName) {
    std::cout << testName << ": ";
    if (actual == expected) {
        std::cout << "PASSED";
    } else {
        std::cout << "FAILED. Expected " << std::to_string(expected) << ", but got " << std::to_string(actual);
    }
    std::cout << "\n";
}

static void test(double actual, double expected, const char* testName) {
    std::cout << testName << ": ";
    if (isZero(actual - expected)) {
        std::cout << "PASSED";
    } else {
        std::cout << "FAILED. Expected " << std::to_string(expected) << ", but got " << std::to_string(actual);
    }
    std::cout << "\n";
}

void checkZeroExpectTrue() {
    test(isZero(0), true, "checkZeroExpectTrue1");
    test(isZero(1e-07), true, "checkZeroExpectTrue2");
    test(isZero(-1e-08), true, "checkZeroExpectTrue3");
}

void checkZeroExpectFalse() {
    test(isZero(1e-06), false, "checkZeroExpectFalse1");
    test(isZero(-1e-06), false, "checkZeroExpectFalse2");

    test(isZero(1e-04), false, "checkZeroExpectFalse3");
    test(isZero(-1e-05), false, "checkZeroExpectFalse4");

    test(isZero(5), false, "checkZeroExpectFalse5");
}

void checkZeroNonFinite() {
    test(isZero(NAN), false, "checkZeroNonFinite1");
    test(isZero(INFINITY), false, "checkZeroNonFinite2");
}

//=================================

void checkLinearSimple(){
    double res = NAN;

    int rootCount = solveLinearEquation(4, 7, res);

    test(rootCount, 1, "checkLinearSimple1");
    test(std::isnan(res), false, "checkLinearSimple1.1");
    test(res, -1.75, "checkLinearSimple1.2");

    rootCount = solveLinearEquation(4, -6, res);
    test(rootCount, 1, "checkLinearSimple2");
    test(std::isnan(res), false, "checkLinearSimple2.1");
    test(res , 1.5, "checkLinearSimple2.2");
}

void checkLinearZeroA() {
    double res = NAN;

    int rootCount = solveLinearEquation(0, 7, res);

    test(rootCount, 0, "checkLinearZeroA1");
    test(std::isnan(res), true, "checkLinearZeroA1.1");
}
void checkLinearZeroB() {
    double res = NAN;

    int rootCount = solveLinearEquation(4, 0, res);

    test(rootCount, 1, "checkLinearZeroB1");
    test(std::isnan(res), false, "checkLinearZeroB1.1");
    test(res, 0.0, "checkLinearZeroB1.2");
}

void checkLinearZeroAll() {
    double res = NAN;

    int rootCount = solveLinearEquation(0, 0, res);

    test(rootCount, INFINITE_ROOTS_COUNT, "checkLinearZeroAll1");
    test(std::isnan(res), true, "checkLinearZeroAll1.1");
}

//=================================

void checkQuadraticSimple() {
    double res1 = NAN;
    double res2 = NAN;

    int rootCount = solveQuadraticEquation(1, 1, -2, res1, res2);

    test(rootCount, 2, "checkQuadraticSimple1");
    test(std::max(res1, res2), 1.0, "checkQuadraticSimple1.1");
    test(std::min(res1, res2), -2.0, "checkQuadraticSimple1.2");
}

void checkQuadraticNoRoots() {
    double res1 = NAN;
    double res2 = NAN;

    int rootCount = solveQuadraticEquation(1, 1, 2, res1, res2);

    test(rootCount, 0, "checkQuadraticNoRoots1");
    test(std::isnan(res1), true, "checkQuadraticNoRoots1.1");
    test(std::isnan(res2), true, "checkQuadraticNoRoots1.2");
}

void checkQuadraticInfiniteRoots() {
    double res1 = NAN;
    double res2 = NAN;

    int rootCount = solveQuadraticEquation(0, 0, 0, res1, res2);

    test(rootCount, INFINITE_ROOTS_COUNT, "checkQuadraticInfiniteRoots1");
    test(std::isnan(res1), true, "checkQuadraticInfiniteRoots1.1");
    test(std::isnan(res2), true, "checkQuadraticInfiniteRoots1.2");
}

void checkQuadraticZeroA() {
    double res1 = NAN;
    double res2 = NAN;

    int rootCount = solveQuadraticEquation(0, 4, 7, res1, res2);

    test(rootCount, 1, "checkQuadraticZeroA1");
    test(res1, -1.75, "checkQuadraticZeroA1.1");
    test(std::isnan(res2), true, "checkQuadraticZeroA1.2");
}

void checkQuadraticZeroB() {
    double res1 = NAN;
    double res2 = NAN;

    int rootCount = solveQuadraticEquation(4, 0, 7, res1, res2);

    test(rootCount, 0, "checkQuadraticZeroB1");
    test(std::isnan(res1), true, "checkQuadraticZeroB1.1");
    test(std::isnan(res2), true, "checkQuadraticZeroB1.2");

    res1 = NAN;
    res2 = NAN;

    rootCount = solveQuadraticEquation(4, 0, -16, res1, res2);

    test(rootCount, 2, "checkQuadraticZeroB2");
    test(std::max(res1, res2), 2.0, "checkQuadraticZeroB2.1");
    test(std::min(res1, res2), -2.0, "checkQuadraticZeroB2.2");
}

void checkQuadraticZeroC() {
    double res1 = NAN;
    double res2 = NAN;

    int rootCount = solveQuadraticEquation(4, 5, 0, res1, res2);

    test(rootCount, 2, "checkQuadraticZeroC1");
    test(res1, 0.0, "checkQuadraticZeroC1.1");
    test(res2, -1.25, "checkQuadraticZeroC1.2");
}

void checkQuadraticZeroAB() {
    double res1 = NAN;
    double res2 = NAN;

    int rootCount = solveQuadraticEquation(0, 0, 6, res1, res2);

    test(rootCount, 0, "checkQuadraticZeroAB1");
    test(std::isnan(res1), true, "checkQuadraticZeroAB1.1");
    test(std::isnan(res2), true, "checkQuadraticZeroAB1.2");
}

void checkQuadraticZeroAC() {
    double res1 = NAN;
    double res2 = NAN;

    int rootCount = solveQuadraticEquation(0, 4, 0, res1, res2);

    test(rootCount, 1, "checkQuadraticZeroAC1");
    test(res1, 0.0, "checkQuadraticZeroAC1.1");
    test(std::isnan(res2), true, "checkQuadraticZeroAC1.2");
}

void checkQuadraticZeroBC() {
    double res1 = NAN;
    double res2 = NAN;

    int rootCount = solveQuadraticEquation(843.5, 0, 0, res1, res2);

    test(rootCount, 1, "checkQuadraticZeroBC1");
    test(res1, 0.0, "checkQuadraticZeroBC1.1");
    test(std::isnan(res2), true, "checkQuadraticZeroBC1.2");
}

//=================================

void checkDiscriminantSimple() {
    double disc = discriminant(1, 1, -2);
    test(disc, 9.0, "checkDiscriminantSimple1");
}

void checkDiscriminantZeroAll() {
    double disc = discriminant(0, 0, 0);
    test(disc, 0.0, "checkDiscriminantZeroAll1");
}

void checkDiscriminantOverflow() {
    double testValue = 1.79769e+308;
    double disc = discriminant(testValue, testValue, testValue);
    test(std::isnan(disc), true, "checkDiscriminantOverflow1");
}

//==================================
void runAllTests() {
    checkZeroExpectTrue();
    checkZeroExpectFalse();
    checkZeroNonFinite();

    checkLinearSimple();
    checkLinearZeroA();
    checkLinearZeroB();
    checkLinearZeroAll();

    checkQuadraticSimple();
    checkQuadraticNoRoots();
    checkQuadraticInfiniteRoots();
    checkQuadraticZeroA();
    checkQuadraticZeroB();
    checkQuadraticZeroC();
    checkQuadraticZeroAB();
    checkQuadraticZeroAC();
    checkQuadraticZeroBC();

    checkDiscriminantSimple();
    checkDiscriminantZeroAll();
    checkDiscriminantOverflow();
}