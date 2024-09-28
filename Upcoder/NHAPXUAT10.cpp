#include <iostream>

using namespace std;

int main() {
    int a; cin >> a;
    int result = a << 1; // a << 1 == a * 2  0000 0101     0000 1010( so 10) // goi la dich bit sang trai
    cout << result;
}