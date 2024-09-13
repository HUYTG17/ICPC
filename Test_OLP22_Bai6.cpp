#define TGH return 0
#define TG ios_base::sync_with_stdio(false)
#define H cin.tie(nullptr)

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    TG; H;
    double a; cin >> a;
    double cd = sqrt(a * 2 / (3 * sqrt(3)));
    cout << fixed << setprecision(8) << cd * 6;
    TGH;
}