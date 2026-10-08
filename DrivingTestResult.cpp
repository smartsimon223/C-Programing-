// Registration Number: CT101/G/26680/25

#include <iostream>
using namespace std;

int main() {
    // i. Declare variables
    double number1;
    double number2;
    double result;
    char op;

    // Ask the user to enter the values
    cout << "Enter first number: ";
    cin >> number1;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> number2;

    // ii. Use switch to perform the selected operation
    // iii. Display the result
    switch (op) {
        case '+':
            result = number1 + number2;
            cout << "Result = " << number1 << " + " << number2 << " = " << result << endl;
            break;

        case '-':
            result = number1 - number2;
            cout << "Result = " << number1 << " - " << number2 << " = " << result << endl;
            break;

        case '*':
            result = number1 * number2;
            cout << "Result = " << number1 << " * " << number2 << " = " << result << endl;
            break;

        case '/':
            // Handle division by zero
            if (number2 == 0) {
                cout << "Error: Division by zero is not allowed." << endl;
            } else {
                result = number1 / number2;
                cout << "Result = " << number1 << " / " << number2 << " = " << result << endl;
            }
            break;

        default:
            cout << "Invalid operator! Please use +, -, * or /." << endl;
    }

    return 0;
}
