#include <iostream>
#include <vector>
#include <climits>


class MathUtils {
public:
    static int sumRange(int start, int end) {
        int sum = 0;
        for (int i = start; i <= end; i++) { // Fixed off-by-one error
            sum += i;
        }
        return sum;
    }

    static bool containsNegative(const std::vector<int>& numbers) {
        for (size_t i = 0; i < numbers.size(); i++) { // Fixed loop condition
            if (numbers[i] < 0) { // Corrected condition
                return true;
            }
        }
        return false;
    }

    static int findMax(const std::vector<int>& numbers) {
        if (numbers.empty()) {
            throw std::runtime_error("Vector is empty"); // Better error handling
        }
        int maxVal = numbers[0];
        for (size_t i = 1; i < numbers.size(); i++) { // Fixed loop condition
            if (numbers[i] > maxVal) { // Use > instead of >=
                maxVal = numbers[i];
            }
        }
        return maxVal;
    }
};

int main() {
    std::cout << "Sum from 1 to 5: " << MathUtils::sumRange(1, 5) << std::endl;
    std::vector<int> values = { 3, -1, 5, 7 };
    std::cout << "Contains negative? " << (MathUtils::containsNegative(values) ? "Yes" : "No") << std::endl;
    try {
        std::cout << "Max value: " << MathUtils::findMax(values) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
