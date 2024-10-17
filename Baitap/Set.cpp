#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    // set<int> se;
    // int a[n];
    // for(int i = 0; i < n; i++) {
    //     cin >> a[i];
    // }
    // for(int i = 0; i < n; i++) {
    //     se.insert(a[i]);
    // }
    // cout << se.size();
    // set<int> se;
    // int n; cin >> n;
    // int a[n];
    // for(int i = 0; i < n; i++) {
    //     cin >> a[i];
    // }
    // int m; cin >> m;
    // int b[m];
    // for(int i = 0; i < m; i++) {
    //     cin >> b[i];
    // }
    // for(int i = 0; i < n; i++) {
    //     se.insert(a[i]);
    // }
    // for(int i = 0; i < m; i++) {
    //     if(se.find(b[i]) != se.end()) {
    //         cout << b[i] << " ";
    //     }
    // }
    // Cho mảng A[] gồm N (1 ≤ N ≤ 106)  phần tử, 
    // hãy liệt kê các giá trị khác nhau trong mảng 
    // theo thứ tự xuất hiện, 
    // mỗi giá trị chỉ liệt kê 1 lần. (dùng set)
    // int n; cin >> n;
    // int a[n];
    // set<int> se;
    // for(int i = 0; i < n; i++) {
    //     cin >> a[i];
    // }
    // for(int i = 0; i < n; i++) {
    //     if(se.find(a[i]) == se.end()) {
    //         cout << a[i] << " ";
    //         se.insert(a[i]);
    //     }
    // } 
    int n; cin >> n;
    int a[n]; 
    set<int> se;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        se.insert(a[i]);
    }
    // for(auto p : se) {
    //     cout << p << " ";
    // }
    cout << "Phan tu max: " << *se.rbegin() << endl;
    cout << "Phan tu min: " << *se.begin();
}