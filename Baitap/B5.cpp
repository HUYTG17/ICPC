// Bài 5 : Nhập vào N phần tử (N là số chẵn và N >=4) mỗi 2 số là 1 cặp và số K . 
// Xuất ra các cặp có tổng bằng K nếu ko có thì xuất không có
// Ví dụ
// Input :
// 8 6
// 1 4 2 5 3 3 0 6 
// Output :
// (3,3) 
// (0,6)
#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, K;
    cin >> n >> K;
    int a[n];
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i += 2) {
        mp[a[i]] = a[i + 1];
    }
    int cnt = 0;
    for(pair<int, int> it : mp) {
        if(it.first + it.second == K) {
            cout << "(" << it.first << "," << it.second << ")\n";
            cnt++;
        }
    }
    if(cnt == 0) {
        cout << "khong co";
    }
}