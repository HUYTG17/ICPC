#include <iostream>
#include <cmath>

using namespace std;

void solve(int x, int n) {
    if(n < 0)
    {
        cout << 1;
    }
    else 
    {
        cout << pow(x, n);
    }
}

int main() {
    int x, n; 
    cin >> x >> n;
    solve(x, n);
    return 0;
}