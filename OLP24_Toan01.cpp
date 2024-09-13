#include <iostream>
using namespace std;
int main() {
    long long n; cin >> n;
    if(n <= 0) {
        cout << 2;
    } else {
        int t = n % 4;
        if(t == 0) cout << 7;
        else if(t == 1) cout << 3;
        else if(t == 2) cout << 5;
        else if(t == 3) cout << 9;
    }
}