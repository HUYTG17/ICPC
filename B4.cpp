// Bài 4 : Cho một danh sách các học sinh và điểm số của họ, 
// tìm học sinh có điểm cao nhất.
// Ví dụ :
// Input :
// 5
// Alice 90
// Bob 85
// Charlie 95
// David 80
// Eve 95
// Output :
// Charlie co diem cao nhat: 95
// Eve co diem cao nhat: 95
#include <iostream>
#include <map>

using namespace std;

int main() {
    int n; cin >> n;
    int a[n];
    map<string, int> mp;
    string s;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> s >> x;
        mp[s] = x;
        //mp.insert({s, x});
    }
    int Max = -99999;
    for(pair<string, int> it : mp) {
        Max = max(Max, it.second);
    }
    for(auto it : mp) {
        if(Max == it.second) {
            cout << it.first << " co diem cao nhat: " << it.second << endl;
        }
    }
}