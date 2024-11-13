#include <iostream>
#include <vector>

using namespace std;

void daySo(vector<int>& a, int n) {
    int sum = 0;
    for(int i : a) {
        sum += i;
    }
    int b = sum % 10, c = (sum / 10) % 10;
    if(b == 0 && c == 0) cout << "DEP";
    else if(b == 5 && c == 5) cout << "TRUNGBINH";
    else cout << "XAU";
}

int main() {
    int n;
    vector<int> v;
    while(cin >> n) {
        if(n == 0) break;
        v.push_back(n);
    }
    daySo(v, n);
    return 0;
}