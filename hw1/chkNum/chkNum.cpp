#include <iostream>

using namespace std;

int main()
{
    // Initialize variables
    int st = 0;
    int ed = 0;
    int c = 0;  // Counter

    for (int i = 1000; i < 10000; i++) {
        // Dispart the number
        st = i / 100;
        ed = i % 100;

        // Check the number
        if (i == (st * st + ed * ed)) {
            cout << i << " == " << st<< "*" << st << " + " << ed << "*" << ed << endl;
            c += 1;
        }
    }
    cout << c << " numbers found" << endl;
    return 0;
}
