#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>


int main()
{
    std::string wordIn;
    std::vector<std::string> vw;        // Vector for different word
    std::vector<unsigned> vc;           // The count for words in word vector
    unsigned max = 0;                   // The count of the mostly occurences word

    // Parse the user input
    std::cout << "Please input a few words :" << std::endl;
    if (std::cin >> wordIn && wordIn.compare("!") != 0) {   // Put the first word into vector
        vw.push_back(wordIn);
        vc.push_back(1);
    }

    // Check the other words
    decltype(vw.begin()) foundIter; // The pointer to the found word
    unsigned ix;                    // The index of the found word in the vector
    while (std::cin >> wordIn && wordIn.compare("!") != 0) {  // Check the other words
        foundIter = std::find(vw.begin(), vw.end(), wordIn);   // Check whether the current word is in the word vector
        if (foundIter != vw.end()) {    // Update the word count if current word is in the word vector
            ix = foundIter - vw.begin();
            if (++vc.at(ix) > max) max = vc.at(ix);
        } else {
            vw.push_back(wordIn);
            vc.push_back(1);
        }
    }

    // Output the mostly occurs and its count
    for (size_t i = 0; i < vw.size(); ++i) {
        if (vc.at(i) == max) {
            std::cout << vw.at(i) << " is the mostly occurs and it has "
                << vc.at(i) << " occurrences"
            << std::endl;
        }
    }
    return 0;
}
