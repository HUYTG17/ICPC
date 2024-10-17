// Bài 3 : Nhập vào 1 mảng gồm N phần tử và 2 số M , K . 
// Tìm vị trí đầu tiên của M và K trong mảng ( nếu không có xuất không có )
// Ví dụ : 
// Input : 
// 8 9 6
// 7 3 4 5 1 2 9 9
// Output :
// 6 
// Không có 
#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, M, K; cin >> n >> M >> K;
    int a[n];
    set<int> se;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        se.insert(a[i]);
    }
    if(se.find(M) != se.end()) {
        cout << distance(se.begin(), se.find(M));
    } else {
        cout << "khong co";
    } 
    cout << endl;
    if(se.find(K) != se.end()) {
        cout << distance(se.begin(), se.find(K));
    } else {
        cout << "khong co";
    }
} 