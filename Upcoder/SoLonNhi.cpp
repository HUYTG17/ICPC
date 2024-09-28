#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int x;
    vector<int> v;
    while(cin >> x) {
        v.push_back(x);
    }
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int cnt = 0;
    for(auto it : v) {
        max1 = max(max1, it);
    }
    for(auto it : v) {
        if(it > max2 && it != max1) {
            cnt++;
            max2 = it;
        }
    }
    cnt == 0 ? cout << -1 : cout << max2;
    return 0;
}