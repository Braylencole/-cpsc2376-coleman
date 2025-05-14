#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;
    int num;

    std::cout << "Enter integers (type 'q' to stop): ";
    while (std::cin >> num) {
        numbers.push_back(num);
    }

    // Clear error state and ignore invalid input (like 'q')
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Numbers in reverse order: ";
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
