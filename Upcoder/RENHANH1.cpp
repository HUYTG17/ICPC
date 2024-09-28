#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int m = n % 3;
    if(n % 3 == 0) cout << n << " chia het cho 3";
    else if(n % 3 != 0) cout << n << " chia 3 du " << m;
    return 0;
}