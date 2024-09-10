// Bài 8 : Nhập vào một dãy các từ và đếm số lần xuất hiện của mỗi từ, sau đó in ra từ có số lần xuất hiện nhiều nhất.
// Ví dụ :
// Input : 
// 7
// apple banana apple orange banana apple apple
// Output : 
// apple xuat hien nhieu nhat: 4 lan

#include <iostream>
#include <map>

using namespace std;

int main() {
    int n; cin >> n;
    string s;
    map<string, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> s;
        mp[s]++;
    }
    int Max = -99999;
    for(auto it : mp) {
        Max = max(Max, it.second);
    }
    for(auto it : mp) {
        if(it.second == Max) {
            cout << it.first << " xuat hien nhieu nhat: " << it.second << " lan";
        }
    }
}