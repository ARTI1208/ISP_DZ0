#include <iostream>
#include <fstream>
#include "equations.h"
#include "tests.h"

void solveAndPrint(double a, double b, double c, double& res1, double& res2) {
    int rootCount = solveQuadraticEquation(a, b, c, res1, res2);

    std::string equationString = std::to_string(a) + " * x^2 + " + std::to_string(b) + " * x + " + std::to_string(c) + " = 0";

    switch (rootCount) {
        case EVALUATION_ERROR:
            std::cout << "An error occurred while processing equation '" << equationString << "'\n";
            break;
        case 0:
            std::cout << "Equation '" << equationString << "' has no roots\n";
            break;
        case 1:
            std::cout << "Equation '" << equationString << "' has one root: x = " << res1 << "\n";
            break;
        case 2:
            std::cout << "Equation '" << equationString << "' has two roots: x1 = " << res1 << "; " << "x2 = " << res2 << "\n";
            break;
        case INFINITE_ROOTS_COUNT:
            std::cout << "Equation '" << equationString << "' has infinite roots count\n";
            break;
        default:
            std::cout << "This should never happen.. Some troubles with equation '" << equationString << "'\n";
    }
}

int main()
{
    runAllTests();

    bool restart;
    double a, b, c, res1, res2;
    std::string input;

    do {
        std::cout << "Input test mode (file/console):\n";
        std::cin >> input;

        if (input == "file") {
            std::cout << "Input file path (coefficients should be separated by spaces, one line = one equation):\n";
            std::cin >> input;

            std::ifstream fileStream(input);
            if (!fileStream.is_open()) {
                std::cout << "Bad filepath\n";
            } else {

                while (fileStream >> a >> b >> c) {
                    solveAndPrint(a, b, c, res1, res2);
                }
            }
        } else {
            std::cout << "Input quadratic equation coefficients:\n";
            std::cin >> a >> b >> c;
            solveAndPrint(a, b, c, res1, res2);
        }

        std::cout << "Would you like to continue solving these damn equations? (y/n) \n";
        std::cin >> input;

        restart = input == "y";

    } while (restart);

    return 0;
}
