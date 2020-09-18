//
// Created by arti1208 on 18.09.2020.
//

#ifndef ISP_DZ1_TESTS_H
#define ISP_DZ1_TESTS_H

void checkZeroExpectTrue();
void checkZeroExpectFalse();
void checkZeroNonFinite();

void checkLinearSimple();
void checkLinearZeroA();
void checkLinearZeroB();
void checkLinearZeroAll();

void checkQuadraticSimple();
void checkQuadraticNoRoots();
void checkQuadraticInfiniteRoots();
void checkQuadraticZeroA();
void checkQuadraticZeroB();
void checkQuadraticZeroC();
void checkQuadraticZeroAB();
void checkQuadraticZeroAC();
void checkQuadraticZeroBC();

void checkDiscriminantSimple();
void checkDiscriminantZeroAll();
void checkDiscriminantOverflow();

void runAllTests();

#endif //ISP_DZ1_TESTS_H
