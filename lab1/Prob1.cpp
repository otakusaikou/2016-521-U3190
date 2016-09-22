#include <iostream>
#include <random>

using namespace std;

int main()
{
    // Generate random number
    random_device rD;                               // The random device
    default_random_engine rE(rD());                 // The default random engine
    uniform_int_distribution<int> dist(0, 9);      // The uniform int distribution
    int randNum[] = {dist(rE), dist(rE)};
    cout << randNum[0] << randNum[1];
    int &firstAns = randNum[0];
    int &secondAns = randNum[1];

    // For user input (from left to right)
    int firstIn;
    int secondIn;
    cout << "Enter your first lottery pick: ";
    cin >> firstIn;
    cout << "Enter your second lottery pick: ";
    cin >> secondIn;

    // Check the number
    cout << "The lottery number is " << firstAns << " and " << secondAns << endl;
    if (firstIn == firstAns) {
        if (secondIn == secondAns) {
            cout << "Exact match: you win $10,000" << endl;
        }
        else {
            cout << "Match one digit: you win $1,000" << endl;
        }
    } else if (firstIn == secondAns) {
        if (secondIn == firstAns) {
            cout << "Match all digits: you win $3,000" << endl;
        } else {
            cout << "Match one digit: you win $1,000" << endl;
        }
    } else {
        if (secondIn == firstAns || secondIn == secondAns) {
            cout << "Match one digit: you win $1,000" << endl;
        } else {
            cout << "Sorry: no match" << endl;
        }
    }
    return 0;
}
