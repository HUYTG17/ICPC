// Bài 7 : Nhập mảng gồm N phần tử . Xuất các số có số lần xuất hiện lớn hơn 1 
// Ví dụ :
// Input :
// 10
// 4 5 6 7 4 5 8 9 4 5
// Output :
// 4 xuat hien 3 lan
// 5 xuat hien 3 lan

#include <iostream>
#include <map>

using namespace std;

int main() {
    int n; cin >> n;
    int a[n];
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    for(auto it : mp) {
        if(it.second > 1) {
            cout << it.first << " xuat hien " << it.second << " lan\n";
        }
    }
}