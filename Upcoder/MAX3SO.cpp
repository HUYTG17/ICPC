#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int x;
    vector<int> v;
    while(cin >> x) {
        v.push_back(x);
    }
    auto min = min_element(v.begin(), v.end());
    auto max = max_element(v.begin(), v.end());
    cout << *max << ' ' << *min;
    return 0;
}