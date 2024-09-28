#include <iostream>

using namespace std;

int main() {
    float a, b; cin >> a >> b;
    if(a == 0 || b == 0) {
        cout << 0;
        return 0;
    }
    if((a > 0 && b > 0) || (a < 0 && b < 0)) cout << "YES";
    else cout << "NO";
}