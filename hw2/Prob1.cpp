#include <iostream>

using namespace std;

int main()
{
    // Initialize variables
    double M;
    int i = 1;
    double sum = 0;     // Function S(N)

    // User input
    cout << "Please input M : ";
    cin >> M;

    // Find the smallist integer making S(N) bigger than M
    sum += 1.0 / i;
    cout << "1/" << i;
    while (sum < M) {
        i++;
        sum += 1.0 / i;
        cout << "+1/" << i;
    }
    cout << "=" << sum;
    cout << "\n\nThe smallist integer N=" << i << endl;
    return 0;
}
