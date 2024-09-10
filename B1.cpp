// Nhập vào 1 chuỗi xuất ra tần số của kí tự ( phân biệt kí tụ thường và kí 
//tự in hoa) 
// theo dạng kí tự - tần suất 
// Ví dụ :
// Input : aabbccABBCCD
// Output : a - 2 , b - 2 , c - 2 , A - 1 , B -2 , C - 2 , D - 1 
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    int cnt  = 0;
    map<char, int> mp;
    for(int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
    }
    for(pair<char, int> p : mp) {
        cout << p.first << " - " << p.second;
        cnt++;
        if(cnt < mp.size()) {
            cout << " , ";
        }
    }
}