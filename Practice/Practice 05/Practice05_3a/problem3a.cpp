#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<int> numbers;
    int num;

    // Prompt user for input
    std::cout << "Enter a list of integers (enter a non-integer to stop): ";
    while (std::cin >> num) {
        numbers.push_back(num);
    }

    // Clear input stream in case of non-integer input
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Use std::for_each to print each number squared
    std::cout << "Squared values: ";
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << (n * n) << " ";
        });
    std::cout << std::endl;

    // Use std::accumulate with a lambda to sum squared values
    int sum_of_squares = std::accumulate(numbers.begin(), numbers.end(), 0, [](int sum, int n) {
        return sum + (n * n);
        });

    std::cout << "Sum of squared values: " << sum_of_squares << std::endl;

    return 0;
}
