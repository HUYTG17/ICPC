// Bài 6 : Nhập N ngày có doanh thu X . Tìm ngày có doanh thu cao nhất 
// Ví dụ :
// Input :
// 6
// 100 200 900 450 750 340
// Output :
// Ngày có doanh thu cao nhất là 3 
#include <iostream>
#include <set>

using namespace std;

int main() {
    int n; cin >> n;
    int a[n];
    set<int> se;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        se.insert(a[i]);
    }
    int max_day = -1;
    int max_value = *se.rbegin();
    for(int i = 1; i <= n; i++) {
        if(a[i] == max_value) {
            max_day = i;
        }
    }
    cout << max_day;
    return 0;
}