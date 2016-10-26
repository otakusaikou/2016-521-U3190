#include <iostream>
#include <string>

int main()
{
    // User input
    int n;
    std::string message;
    std::cout << "Please input a message:" << std::endl;
    std::getline(std::cin, message);
    std::cout << "The 'n' position further along the alphabet:" << std::endl;
    std::cin >> n;

    // Output the encoded message
    std::cout << "The encoded message:" << std::endl;
    for (auto c : message) {
        if (c >= 65 && c <= 90) {           // For upper case characters
            std::cout << static_cast<char>(((c + n - 'A') % 26) + 'A');
        } else if (c >= 97 && c <= 122) {   // For lower case characters
            std::cout << static_cast<char>(((c + n - 'a') % 26) + 'a');
        } else{                             // For other characters
            std::cout << c;
        }
    }
    std::cout << std::endl;
    return 0;
}
