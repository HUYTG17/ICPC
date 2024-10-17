// Đề bài : Cho mảng A[] gồm N (1≤N≤106) các số nguyên 32 bit,
// hãy đếm xem trong mảng có bao nhiêu giá trị khác nhau.
// input :
// 12
// 1 3 2 1 2 3 4 1 5 8 10 2
// output 
// 7
#include <iostream>
#include <map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    map<int, int> mp;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        mp[a[i]]++;
    }
    //cout << mp.size() << endl;
    // for(pair<int, int> it : mp) {
    //     cout << "key = " << it.first << " value = " << it.second << endl;
    // }
    // for(auto it = mp.rbegin(); it != mp.rend(); ++it) {
    //     cout << "key = " << it->first << " value = " << it->second << endl;
    // }
    // for(pair<int, int> it : mp) {
    //     cout << it.first << " xuat hien " << it.second << "\n";
    // }
    // for(auto it : mp) {
    //     cout << it.first << " " << it.second << endl;
    //}
    for(int i = 0; i < n; i++) {
        if(mp[a[i]] != 0) {
            cout << a[i] << " xuat hien " << mp[a[i]] << endl;
            mp[a[i]] = 0;
        }
    }
}