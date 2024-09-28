#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    if(a == 0) {
        if(b == 0) cout << "VSN";
        else cout << "VN";
    }
    else {
        cout << fixed << setprecision(2) << -b / a;
    }
    return 0;
}