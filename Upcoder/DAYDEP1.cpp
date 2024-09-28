#include <iostream>
#include <vector>

using namespace std;

void daySo(int n, vector<int>& a) {
    int sum = 0;
    for(int i : a) {
        sum += i;
    }
    sum = sum % 10;
    if(sum == 0) cout << "DEP";
    else if(sum == 5) cout << "TRUNGBINH";
    else cout << "XAU";
}
int main() {
    int n;
    vector<int> v;
    while(cin >> n) {
        if(n == 0) break;
        v.push_back(n);
    }
    daySo(n, v);
}