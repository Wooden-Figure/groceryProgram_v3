#include "FileHandler.h"
#include "UserInterface.h"
#include <iostream>

int main() {
    std::string response; // holds the user input
    bool isValidInput = false;  // determines if the input is the required format

    // main loop for the program
    while (!isValidInput) {
        std::cout << "Hello customer! I hope your day is going well." << std::endl;
        std::cout << "Do you want to start the item-tracking program for Corner Grocer? (yes/no): ";
        std::cin >> response;

        // makes user input case-insensitive
        for (char &c : response) {
            c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        }

        // checks if the users put in yes/ no
        if (response == "yes" || response == "no") {
            isValidInput = true;  // if user puts yes, loop exits
        } else {
            std::cout << "\nInvalid input. Please type 'yes' or 'no'.\n";
            std::cout << "\n";// if the user does not, loop continues
        }
    }

    if (response == "no") {
        std::cout << "Program not started. Exiting...\n";
        return 0;  // quits the program if user types no
    }

    std::cout << "\n";
    std::cout << "****************************************************\n";
    std::cout << "*                    WELCOME                       *\n";
    std::cout << "*                     to the                       *\n";
    std::cout << "*         Corner Grocer Item Tracking System!      *\n";
    std::cout << "****************************************************";
    std::cout << "\n";

    // initializes the output/ input files
    FileHandler fileHandler("CS210_Project_Three_Input_File.txt", "frequency.dat");
    std::map<std::string, int> itemFrequency = fileHandler.readItemsIntoMap();

    if (itemFrequency.empty()) {
        std::cout << "Error reading input file or file is empty.\n";
        return 1;
    }

    // inputs the data to a backup
    fileHandler.writeMapToFile(itemFrequency);

    // loop that continues after the user has inputted their first number 1-4
    [[maybe_unused]] UserInterface ui;
    while (true) {
        UserInterface::displayMenu(); // shows the menu from the user interface
        int choice = UserInterface::getUserChoice(); // receives the user's response
        UserInterface::handleChoice(choice, itemFrequency);

        // ask the user for continuation of the program, if not, then the loop breaks
        if (!UserInterface::continuePrompt("\nDo you want to continue? (yes/no): \n")) {
            std::cout << "\n";
            break; // exits the loop
        }
    }

    std::cout << "\nThank you for using the Corner Grocer Item Tracking System!\n";
    return 0;
}
