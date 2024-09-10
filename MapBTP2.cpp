#include <iostream>
#include <map>
// #include <sstream>
// input
// 5
// 1 2 3 4 5
// 4 5 6 7 8
// output
// 1 2 3 4 5 6 7 8
using namespace std;
int main() {
    // ios_base::sync_with_stdio(false);
    // string s;
    // getline(cin, s);
    // stringstream ss(s);
    // string word;
    // map<string, int> mp;
    // while(cin >> word) {
    //     mp[word]++;
    // }
    // for(pair<string, int> it : mp) {
    //     cout << it.first << " xuat hien " << it.second << endl;
    // }
    int n; cin >> n;
    int a[n], b[n];
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++) {
        mp[a[i]] = 1;
    }
    for(int i = 0; i < n; i++) {
        if(mp[b[i]] == 1) {
            mp[b[i]] = 2;
        }
    }
    for(pair<int, int> it : mp) {
        if(it.second == 2) {
            cout << it.first << " ";
        }
    }
}