#include <bits/stdc++.h>

using namespace std;

string minNumber(string a) {
    int n = a.size();
    for(int i = n - 2; i > 0; i--) {
        if((a[i] - '0') % 2 != (a[i - 1]  - '0') % 2 && a[i] < a[i - 1]) {
            swap(a[i], a[i - 1]);
        }
    }
    return a; 
}
int main() {
    int n; cin >> n;
    while(n--) {
        string a; cin >> a;
        cout << minNumber(a) << '\n';
    }
    return 0;
}