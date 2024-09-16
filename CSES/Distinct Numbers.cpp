#include <iostream>
#include <vector>
#include <set>

using namespace std;
int main() {
    int n; cin >> n;
    vector<int> v(n);
    set<int> se;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        se.insert(v[i]);
    }
    cout << se.size();
}