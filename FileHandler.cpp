#include "FileHandler.h"
#include <fstream>
#include <iostream>

// initializes the input and output file names
FileHandler::FileHandler(const std::string& inputFile, const std::string& outputFile) :
        inputFileName(inputFile),
        outputFileName(outputFile) {}

// reads the information from a file and inputs the frequency into the map function
std::map<std::string, int> FileHandler::readItemsIntoMap() {
    std::map<std::string, int> itemFrequency;  // map that stores the freq of items
    std::ifstream inFile(inputFileName);
    std::string item;                          // holds the information from the file

    // determines if the file opened properly
    if (!inFile) {
        std::cerr << "Error opening input file: " << inputFileName << std::endl;  // outputs an error message
        return itemFrequency;  // if the file isn't opened, this is shown
    }

    // increments the count in the map
    while (inFile >> item) {
        ++itemFrequency[item];
    }

    inFile.close();  // closes the input file
    return itemFrequency;
}

// writes the innards of the map to a file
void FileHandler::writeMapToFile(const std::map<std::string, int>& itemMap) {
    std::ofstream outFile(outputFileName);  // opens output for the provided file
    // sees if the file was opener
    if (!outFile) {
        std::cerr << "Error opening output file: " << outputFileName << std::endl;  // error message
        return;
    }

    // loops through every item and the frequency
    for (const auto& pair : itemMap) {
        outFile << pair.first << ": " << pair.second << std::endl;
    }

    outFile.close();  // closes the output
}
