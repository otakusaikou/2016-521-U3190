#include <iostream>

using namespace std;

int main()
{
    int st;
    int ed;
    cout << "Please input the range of Celsius temperature values:";
    cin >> st >> ed;
    cout << "Celsius\tFahrenheit" << endl;
    for (int i = st; i <= ed; i++) {
        cout << i << "\t" << i * 9.0 / 5.0 + 32 << endl;
    }
}
