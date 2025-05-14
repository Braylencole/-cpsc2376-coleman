#include <iostream>
#include <vector>
#include <algorithm> 

int main() {
   
    std::vector<int> numbers = { 12, 45, 23, 78, 56, 89, 34, 67 };

    if (numbers.empty()) {
        std::cerr << "Error: The vector is empty!" << std::endl;
        return 1;
    }

    // Find the largest element using std::max_element
    auto max_it = std::max_element(numbers.begin(), numbers.end());
    // Find the smallest element using std::min_element
    auto min_it = std::min_element(numbers.begin(), numbers.end());

    std::cout << "Largest element: " << *max_it << std::endl;
    std::cout << "Smallest element: " << *min_it << std::endl;

    return 0;
}
