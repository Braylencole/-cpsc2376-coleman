#include <iostream>
#include "Fraction.h"
#include "MixedFraction.h"

void displayMenu() 
{
    std::cout << "\nYour Options:\n"
        << "1. Enter a fraction manually\n"
        << "2. Add\n"
        << "3. Subtract\n"
        << "4. Multiply by a fraction\n"
        << "5. Divide by a fraction\n"
        << "6. Display as a Mixed Fraction\n"
        << "7. Clear\n"
        << "8. Exit\n";
}

int main() 
{
    Fraction currentFraction; 
    int option;

    while (true) 
    {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> option;

        try 
        {
            if (option == 1) 
            {
                int num, den;
                std::cout << "Enter numerator and denominator: ";
                std::cin >> num >> den;
                currentFraction.setNumerator(num);
                currentFraction.setDenominator(den);
                std::cout << "Current Fraction: " << currentFraction << std::endl;
            }
            else if (option == 2 || option == 3 || option == 4 || option == 5)
            {
                int num, den;
                std::cout << "Enter numerator and denominator: ";
                std::cin >> num >> den;
                Fraction input(num, den);
                if (option == 2) currentFraction = currentFraction + input;
                else if (option == 3) currentFraction = currentFraction - input;
                else if (option == 4) currentFraction = currentFraction * input;
                else if (option == 5) currentFraction = currentFraction / input;
                std::cout << "Current Fraction: " << currentFraction << std::endl;
            }
            else if (option == 6) 
            {
                MixedFraction mixedFraction(currentFraction);
                std::cout << "Mixed Fraction: " << mixedFraction << std::endl;
            }
            else if (option == 7) 
            {
                currentFraction = Fraction();
                std::cout << "The Current Fraction reset to 0/1\n";
            }
            else if (option == 8) 
            {
                std::cout << "Leaving the menu...\n";
                break;
            }
            else 
            {
                std::cout << "Try again.\n";
            }
        }
        catch (const std::exception& e) 
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}