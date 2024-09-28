/*#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
    int n, a, b; cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, 1}); 
        v.push_back({b, -1});
    }
    sort(v.begin(), v.end());
    int sum = 0;
    int Max = INT_MIN;
    for(auto it : v) {
        sum += it.second;
        Max = max(Max, sum);
    }
    cout << Max;

    return 0;
}*/
#include <iostream>
#include <map>
#include <climits>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
    int n, a, b; cin >> n;
    map<int, int> v;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        v.insert({a, 1}); 
        v.insert({b, -1});
    }
    int sum = 0;
    int Max = INT_MIN;
    for(auto it : v) {
        sum += it.second;
        Max = max(Max, sum);
    }
    cout << Max;
    return 0;
}