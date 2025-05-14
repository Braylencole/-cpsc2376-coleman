#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

// Template function for calculation
template <typename T>
T calculate(T a, T b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return (b != 0) ? a / b : throw runtime_error("Division by zero");
    default: throw invalid_argument("Invalid operation");
    }
}

// Function to determine if input is integer or double
template <typename T>
T getNumber() {
    string input;
    cin >> input;
    if (input.find('.') != string::npos) {
        return static_cast<T>(stod(input));
    }
    return static_cast<T>(stoi(input));
}

int main() {
    cout << "Enter first number: ";
    string firstInput;
    cin >> firstInput;
    bool isDouble = firstInput.find('.') != string::npos;

    cout << "Enter second number: ";
    string secondInput;
    cin >> secondInput;
    isDouble = isDouble || secondInput.find('.') != string::npos;

    cout << "Enter operation (+, -, *, /): ";
    char op;
    cin >> op;

    try {
        if (isDouble) {
            double a = stod(firstInput);
            double b = stod(secondInput);
            double result = calculate(a, b, op);
            cout << "Result: " << fixed << setprecision(2) << result << endl;
        }
        else {
            int a = stoi(firstInput);
            int b = stoi(secondInput);
            int result = calculate(a, b, op);
            cout << "Result: " << result << endl;
        }
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
