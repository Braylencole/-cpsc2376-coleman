#include <iostream>
#include <iomanip>
#include <limits>

// Function to convert temperature
double convertTemperature(double temp, char scale = 'F') {
    if (scale == 'F' || scale == 'f') {
        return (temp * 9.0 / 5.0) + 32.0; // Celsius to Fahrenheit
    }
    else if (scale == 'C' || scale == 'c') {
        return (temp - 32.0) * 5.0 / 9.0; // Fahrenheit to Celsius
    }
    else {
        std::cerr << "Invalid scale. Use 'C' or 'F'." << std::endl;
        return temp; // Return the original value if invalid input
    }
}

int main() {
    int choice;
    double temperature, converted;
    char scale;

    std::cout << "1. Convert Celsius to Fahrenheit\n";
    std::cout << "2. Convert Fahrenheit to Celsius\n";
    std::cout << "Choose an option: ";
    while (!(std::cin >> choice) || (choice != 1 && choice != 2)) {
        std::cerr << "Invalid choice. Please enter 1 or 2: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (choice == 1) {
        scale = 'F';
        std::cout << "Enter temperature in Celsius: ";
    }
    else {
        scale = 'C';
        std::cout << "Enter temperature in Fahrenheit: ";
    }

    while (!(std::cin >> temperature)) {
        std::cerr << "Invalid input. Please enter a numeric value: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    converted = convertTemperature(temperature, scale);

    std::cout << std::fixed << std::setprecision(2);
    if (scale == 'F') {
        std::cout << "Converted: " << converted << std::endl;
    }
    else {
        std::cout << "Converted: " << converted << std::endl;
    }

    return 0;
}
