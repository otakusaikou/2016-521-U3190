#include <iostream>

using namespace std;

int main()
{
    // Initialize variables
    int st = 0;
    int ed = 0;
    int c = 0;      // Counter
    int i = 1000;   // The loop number
    while (i < 10000) {
        // Dispart the number
        st = i / 100;
        ed = i % 100;

        // Check the number
        if (i == (st * st + ed * ed)) {
            cout << i << " == " << st<< "*" << st << " + " << ed << "*" << ed << endl;
            c += 1;
        }
        i++;
    }
    cout << c << " numbers found" << endl;
    return 0;
}
