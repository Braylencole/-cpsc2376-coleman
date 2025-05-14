#include <iostream>
#include <string>

int main() {
    // Define the potion amounts
    float redPotion{ 0.0f };  // Amount of red potion in mL
    float bluePotion{ 0.0f }; // Amount of blue potion in mL
    float* flask{ nullptr };  // Pointer to the selected potion

    std::string potionChoice;
    float amountToAdd;

    // While loop for potion brewing
    while (true) {
        std::cout << "Which potion to add liquid to (Red or Blue)? (Type 'Done' to finish): ";
        std::cin >> potionChoice;

        // If user types "Done", break out of the loop
        if (potionChoice == "Done") {
            break;
        }

        // Set the flask pointer to the correct potion based on user input
        if (potionChoice == "Red") {
            flask = &redPotion;
        }
        else if (potionChoice == "Blue") {
            flask = &bluePotion;
        }
        else {
            std::cout << "Invalid choice. Please enter 'Red' or 'Blue'.\n";
            continue;
        }

        // Ask for the amount to add to the selected potion
        std::cout << "How many milliliters to add? ";
        std::cin >> amountToAdd;

        // Update the selected potion's amount
        if (flask != nullptr) {
            *flask += amountToAdd;
        }

        // Display the current potion levels
        std::cout << "Red Potion: " << redPotion << " mL\n";
        std::cout << "Blue Potion: " << bluePotion << " mL\n";
    }

    return 0;
}
