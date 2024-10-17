// Nhập vào 1 mảng gồm N phần tử và xuất ra số lần xuất hiện từ trên xuống thấp 
// ( nếu bằng nhau số lần thì cũng sắp từ trên xuống thấp)
// Ví dụ 
// Input :
// 10
// 1 3 3 1 1 5 9 5 5 7
// Output : 5 1 3 9 7
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
// bool cmp(pair<int, int>& a, pair<int, int>& b) {
//     if(a.second == b.second) 
//         return a.first > b.first;
//     return a.second > b.second;
// }
                   

int main() {
    int n; cin >> n;
    int a[n];
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        mp[a[i]]++;
    }
    vector<pair<int, int>> v(mp.begin(), mp.end());
    //sort(v.begin(), v.end(), cmp);
    // sort
    stable_sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if(a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    });
    for(auto it : v) {
        cout << it.first << " ";
    }
}