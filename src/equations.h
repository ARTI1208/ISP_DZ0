/**
 * @file
 *
 * @brief Equation solver
 */

#ifndef ISP_DZ1_EQUATIONS_H
#define ISP_DZ1_EQUATIONS_H

const double EPSILON = 1e-06;
const int EVALUATION_ERROR = -1;
const int INFINITE_ROOTS_COUNT = -2;

/**
 * Checks whether the given floating point value is close to zero
 *
 * @param value The value you want to check
 * @return true if value is close to zero, false otherwise
 */
bool isZero(double value);

/**
 * Solves equation of form a * x + b = 0 (linear equation)
 *
 * @param a First parameter of equation
 * @param b Second parameter of equation
 * @param[out] res Root of equation, if present
 * @return 0 if equation can't be solved, 1 if there is one root and INFINITE_ROOTS_COUNT if root count is infinite
 */
int solveLinearEquation(double a, double b, double& res);

/**
 * Solves equation of form a * x^2 + b * x + c = 0 (quadratic equation)
 *
 * @param a First parameter of equation
 * @param b Second parameter of equation
 * @param c Third parameter of equation
 * @param[out] res1 First root of equation, if present
 * @param[out] res2 Second root of equation, if present
 * @return Equation's root count
 */
int solveQuadraticEquation(double a, double b, double c, double& res1, double& res2);

/**
 * Calculates quadratic equation discriminant, that is b^2 - 4 * a * c
 *
 * @param a First parameter of equation
 * @param b Second parameter of equation
 * @param c Third parameter of equation
 * @return Equation's discriminant
 */
double discriminant(double a, double b, double c);



#endif //ISP_DZ1_EQUATIONS_H
