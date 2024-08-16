#include <iostream>

void interactive_mode();
void calculate(double operand1, double operand2, char op);

int main(int argc, char **argv)
{
    if (argc == 1) { // No arguments passed, go interactive
        interactive_mode();
        return 0;
    }

    if (argc != 4) { // Batch mode. Three arguments must be passed
        std::cerr << "SimpleCalculator is running in batch mode. You must pass exactly three paramters. For example:\n";
        std::cerr << "\tSimpleCalculator 2 + 2" << std::endl;
        return 1;
    }

    double operand1 = std::atof(argv[1]);
    double operand2 = std::atof(argv[3]);

    char op = argv[2][0];

    if (op != '+' && op != '-' && op != 'x' && op != '/') {
        std::cerr << "SimpleCalculator understands the operators +, -, x, /" << std::endl;
        return 1;
    }

    calculate(operand1, operand2, op);

    return 0;
}

void interactive_mode()
{
    char operation {};

    do {
        double operand1 {};
        double operand2 {};

        std::cout << "Enter an operator (Q to quit): ";
        std::cin >> operation;

        if (operation == 'Q' || operation == 'q') {
            break;
        }

        std::cout << "Enter two operands separated by a space: ";
        std::cin >> operand1 >> operand2;

        if (operation != '+' && operation != '-' && operation != 'x' && operation != '/') {
            std::cerr << "SimpleCalculator understands the operators +, -, x, /" << std::endl;
            continue;
        }

        calculate(operand1, operand2, operation);

    } while (true);
}

void calculate(double operand1, double operand2, char op)
{
    switch (op) {
    case '+':
        std::cout << operand1 << " + " << operand2 << " = " << (operand1 + operand2) << std::endl;
        break;
    case '-':
        std::cout << operand1 << " - " << operand2 << " = " << (operand1 - operand2) << std::endl;
        break;
    case 'x':
        std::cout << operand1 << " x " << operand2 << " = " << (operand1 * operand2) << std::endl;
        break;
    case '/':
        std::cout << operand1 << " / " << operand2 << " = " << (operand1 / operand2) << std::endl;
        break;
    }
}
