#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <numeric>

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
    std::cout << std::endl
        << "File was opened correctly." << std::endl
        << std::endl;

    // Analyze the paragraph
    std::vector<unsigned> punctVec;         // Punctuation counter
    std::vector<unsigned> spaceVec;         // Space counter
    std::string line;
    decltype(punctVec.size()) i = 0;
    while (std::getline(fin, line)) {
        punctVec.push_back(0);
        spaceVec.push_back(0);
        for (auto &c : line) {
            if (std::ispunct(c)) {
                ++punctVec.at(i);
            } else if (std::isspace(c)){
                ++spaceVec.at(i);
            }
        }
        ++i;
    }

    // Output results
    std::cout << "Total punctuation: " << std::accumulate(punctVec.begin(), punctVec.end(), 0) << std::endl
        << "Total spaces: " << std::accumulate(spaceVec.begin(), spaceVec.end(), 0) << std::endl
        << std::endl;

    for (decltype(punctVec.size()) n = 0; n != punctVec.size(); ++n) {
        std::cout << "Line "
            << (n + 1) << std::endl
            << "\tPunctuation: " << punctVec.at(n) << std::endl
            << "\tSpaces: " << spaceVec.at(n) << std::endl
        << std::endl;
    }
    return 0;
}
