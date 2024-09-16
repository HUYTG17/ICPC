#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    if(n < 100) {
        cout << -1;
        return 0;
    }
    cout << (n / 100) % 10;
}