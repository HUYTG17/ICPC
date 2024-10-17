#include <iostream>

#include <vector>
using namespace std;

int main(){
    // int n, m; cin >> n >> m;
    // vector<vector<int>> v;
    // vector<vector<int>> v1(n, vector<int>(m));
    
    // pair<int, pair<char, int>> p1 = make_pair(28, make_pair('@', 100));
    // pair<pair<int, int>, pair<int, int>> p2 = {{10, 20}, {20, 30}};
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        mp[a[i]]++;
        mp.insert({a[i], 1});
        mp[a[i]] = i;
    }
    return 0;
    
}