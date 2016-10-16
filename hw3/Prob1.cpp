#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

// Function for reading text file
std::ifstream &openFile(std::ifstream &fin, const std::string &fileName)
{
    fin.close();                    // Close in case it was already open
    fin.clear();                    // Clear any existing errors
    fin.open(fileName.c_str());     // Open the file with given file name
    return fin;
}

int main()
{
    // User input
    std::string fileName;
    std::cout << "Please input the file name." << std::endl
        << "input here: ";

    // Open text file
    std::ifstream fin;
    std::cin >> fileName;
    while (!openFile(fin, fileName)) {
        std::cerr << std::endl
            << "The file does not exist!" << std::endl
            << "Please input the file name again." << std::endl
            << "input here: ";
        std::cin >> fileName;
    }

    // Read the text file
    std::vector<std::string> lineVec;         // Vector for lines
    std::string line;
    while (std::getline(fin, line)) {
        lineVec.push_back(line);
    }

    // Output the contents of first paragraph also handle the case that
    // there is only one paragraph in the input file
    std::cout << std::endl
        << "The first paragraph of the input file is" << std::endl
        << std::endl;

    for (auto lineIter = lineVec.begin(); lineIter != lineVec.end() && !(*lineIter).empty(); ++lineIter) {
        std::cout << *lineIter << std::endl;
    }
    fin.close();
    return 0;
}
