
#include <iostream>
#include <vector>

void printVector(const std::vector<int>& nums) 
{
    std::cout << "Vector contents: ";
    for (size_t i = 0; i < nums.size(); ++i) 
    {
        std::cout << nums.at(i) << " "; 
    }
    std::cout << std::endl;
}


void doubleVector(std::vector<int>& nums) 
{
    for (size_t i = 0; i < nums.size(); ++i) {
        nums.at(i) *= 2; 
    }
}


void printSum(const std::vector<int>& nums) 
{
    int sum = 0;
    for (size_t i = 0; i < nums.size(); ++i) 
    {
        sum += nums.at(i); 
    }
    std::cout << "Sum of vector elements: " << sum << std::endl;
}

void printMultiples(const std::vector<int>& nums, int value) 
{
    std::cout << "Multiples of " << value << ": ";
    bool found = false;
    for (size_t i = 0; i < nums.size(); ++i) 
    {
        if (nums.at(i) % value == 0) 
        { 
            std::cout << nums.at(i) << " ";
            found = true;
        }
    }
    if (!found) std::cout << "None";
    std::cout << std::endl;
}


int main()
{
    std::vector<int> nums = { 5 }; 
    int choice = 0;

    while (choice != 6) 
    {
        
        std::cout << "\nMenu:\n"
            << "1. Add an item to the vector\n"
            << "2. Print the vector\n"
            << "3. Double the vector\n"
            << "4. Find the sum\n"
            << "5. Print multiples of a value\n"
            << "6. Exit\n"
            << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) 
        {
    
            int num;
            std::cout << "Enter a number to add to the vector: ";
            std::cin >> num;
            nums.push_back(num); 
        }
        else if (choice == 2) 
        {
    
            printVector(nums);
        }
        else if (choice == 3) 
        {
           
            doubleVector(nums);
            std::cout << "The vector is doubled.\n";
        }
        else if (choice == 4) 
        {
       
            printSum(nums);
        }
        else if (choice == 5) 
        {
        
            int value;
            std::cout << "Enter a number to find multiples: ";
            std::cin >> value;
            printMultiples(nums, value);
        }
        else if (choice == 6) 
        {
           
            std::cout << "Exiting the program.\n";
        }
        else {
        
            std::cout << "Try again!\n";
        }
    }

    return 0;
}
