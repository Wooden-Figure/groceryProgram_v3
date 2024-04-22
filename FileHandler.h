#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <map>

// FileHandler class declaration
class FileHandler {
private:
    std::string inputFileName;  // holds the input file
    std::string outputFileName; // holds the output file

public:
    // constructor for the class that takes two strings as arguments: the names of the input and output files
    FileHandler(const std::string& inputFile, const std::string& outputFile);

    // reads items from the specified input file and returns a map of items to their frequencies
    std::map<std::string, int> readItemsIntoMap();

    // writes the map (item frequencies) to the specified output
    void writeMapToFile(const std::map<std::string, int>& itemMap);

};

#endif // FILEHANDLER_H
