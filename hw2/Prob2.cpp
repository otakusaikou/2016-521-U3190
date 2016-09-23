#include <iostream>
#include <cmath>        // hypot
#include <random>       // random_device, default_random_engine, uniform_real_distribution

using namespace std;

int main()
{
    // Initialize variables
    int inCircle = 0;       // The number that the point lie the quadrant
    int n;                  // Total number of throws
    const double PI = 3.14159265;
    printf("Use a const double to prescribe the value PI=%.8f\n", PI);

    // Generate random number
    random_device rD;
    default_random_engine rE(rD());
    uniform_real_distribution<> dist(0.0, 1.0);

    // User input
    cout << "Enter the number of throw: ";
    cin >> n;

    // Compute PI with Monte Carlo method
    for (int i = 0; i < n; i++) {
        if (hypot(dist(rE), dist(rE)) <= 1) inCircle++;     // Check if the point lie the quadrant
    }
    double PI_MC = (1.0 * inCircle / n) * 4;

    // Output the result
    printf("PI = %.8f", PI_MC);
    printf("   error%%= %.8f\n", (abs(PI_MC - PI) / PI * 100));
    return 0;
}
