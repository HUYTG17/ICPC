#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float a, b;
    cin >> a >> b;
    cout << fixed << setprecision(1) << -b / a;
}
