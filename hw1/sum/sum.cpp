#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    int num = 0;
    cout << "Enter a sequence of numbers to be summed: ";
    while (cin >> num && num >= 0) { // Check the input type
        sum += num;
    }
    cout << "Sum is: " << sum << endl;
    return 0;
}
