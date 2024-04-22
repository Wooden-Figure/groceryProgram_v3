#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <string>
#include <map>

// defines the UserInterface class
class UserInterface {
public:
    // displays the menu options
    static void displayMenu();

    // gets the user's menu choice
    static int getUserChoice(); // prompts  user for a choice and ensures it is within the specified range

    // executes an action based on the user's menu choice
    static void handleChoice(int choice, const std::map<std::string, int>& itemFrequency);

    // prompts the user to continue/ stop using the program
    static bool continuePrompt(const std::string& query);
    // asks yes/ no question

    // reads a single word from standard input, formats, and returns it
    static std::string getItemName();

    // input validation
    static bool validateResponse(const std::string& response);

};

#endif // USERINTERFACE_H
