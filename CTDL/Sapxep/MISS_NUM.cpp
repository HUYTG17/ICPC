#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> v(n);
    vector<int> count(100, 0);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        count[v[i]]++;
    }
    int min = 99999;
    for(int i = 0; i < n; i++) {
        if(min > v[i]) {
            min = v[i];
        }
    }
    for(int i = 0; i <= n; i++) {
        if(count[i] == 0) {
            cout << i;
        }
    }
}