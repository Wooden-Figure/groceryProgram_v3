#include "UserInterface.h"
#include <iostream>
#include <limits>

// shows the main menu to the user
void UserInterface::displayMenu() {
    std::cout << "\n";
    std::cout << "Menu Options:\n";
    std::cout << "1. Search for an item frequency\n";
    std::cout << "2. Display all item frequencies\n";
    std::cout << "3. Display histogram of frequencies\n";
    std::cout << "4. Exit program\n";
}

// ensures a valid answer is received from the user
int UserInterface::getUserChoice() {
    int choice; // holds the user's choice of 1-4
    // validation input
    while (!(std::cin >> choice) || choice < 1 || choice > 4) {
        std::cout << "Invalid option, please enter a number between 1 and 4: ";
        std::cin.clear();  // for any non integer inputs by the user
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return choice;
}

// puts the user's answer in the same format as the project three input file, for if they chose option 2
std::string UserInterface::getItemName() {
    std::string itemName; // storage for the inputted item
    std::cin >> itemName; // reads the item
    // makes the first letter capitol and the rest lowercase
    if (!itemName.empty()) {
        itemName[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(itemName[0]))); // capitalize first letter
        for (size_t i = 1; i < itemName.length(); i++) {
            itemName[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(itemName[i]))); // lowercase the rest
        }
    }
    return itemName;
}

// handles the user's menu choice
void UserInterface::handleChoice(int choice, const std::map<std::string, int>& itemFrequency) {
    std::string itemName;
    // performs an action based on user choice
    switch(choice) {
        case 1:
            std::cout << "Enter the name of the item you wish to find:";
            itemName = getItemName();  // gets the item name from user
            // checks if the item exists in the map and print its frequency
            if (itemFrequency.find(itemName) != itemFrequency.end()) {
                std::cout << itemName << ": " << itemFrequency.at(itemName) << std::endl;
            } else {
                std::cout << "Item not found.\n";
            }
            break;
        case 2:
            // print all items and their frequencies
            for (const auto& item : itemFrequency) {
                std::cout << item.first << ": " << item.second << std::endl;
            }
            break;
        case 3:
            std::cout << "Histogram of Item Frequencies:\n";
            // histogram for every item
            for (const auto& item : itemFrequency) {
                std::cout << item.first << ": " << std::string(item.second, '*') << std::endl;
            }
            break;
        case 4:
            std::cout << "Exiting the program...\n";
            exit(0);
        default:  // all other answers
            std::cout << "An unexpected error occurred. Please try again.\n";
            break;
    }
}

// input validation
bool UserInterface::continuePrompt(const std::string& query) {
    std::string response;
    do {
        std::cout << query;
        std::cin >> response;
    } while (!validateResponse(response));
    return response == "yes";
}

// input validation for yes/no response
bool UserInterface::validateResponse(const std::string& response) {
    if (response == "yes" || response == "no") {
        return true;
    } else {
        std::cout << "Invalid response. Please enter 'yes' or 'no'.\n"; // Prompt for valid input
        return false;
    }
}
