#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int a[n]; 
    multiset<int> se;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        se.insert(a[i]);
    }
    // for(int x : se) {
    //     cout << x << " ";
    // }
    // auto it = se.upper_bound(2);
    // if(it != se.end()) {
    //     --it;
    // }
    // cout << distance(se.begin(), it); tìm số 2 thứ 2
    auto it = se.find(2);
    cout << distance(se.begin(), it);
}

