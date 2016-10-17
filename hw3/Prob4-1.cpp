#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>


int main()
{
    std::string wordIn;
    std::vector<std::string> vw;        // Vector for different word
    std::vector<unsigned> vc;           // The count for words in word vector
    size_t max = 0;                     // The longest size of the word in input sentence

    // Parse the user input
    std::cout << "Please input a few words :" << std::endl;
    if (std::cin >> wordIn && wordIn.compare("!") != 0) {   // Put the first word into vector
        vw.push_back(wordIn);
        vc.push_back(1);
    }

    // Check the other words
    decltype(vw.begin()) foundIter; // The pointer to the found word
    unsigned ix;                    // The index of the found word in the vector
    while (std::cin >> wordIn && wordIn.compare("!") != 0) {
        if (wordIn.size() > max) max = wordIn.size();           // Update the longest size
        foundIter = std::find(vw.begin(), vw.end(), wordIn);    // Check whether the current word is in the word vector
        if (foundIter != vw.end()) {    // Update the word count if current word is in the word vector
            ix = foundIter - vw.begin();
            ++vc.at(ix);
        } else {
            vw.push_back(wordIn);
            vc.push_back(1);
        }
    }

    // Output the longest word and its count
    for (size_t i = 0; i < vw.size(); ++i) {
        if (vw.at(i).size() == max) {
            std::cout << "The longest word is " << vw.at(i)
                << " and it has " << vc.at(i) << " occurrences"
            << std::endl;
        }
    }
    return 0;
}
