#include <iostream>
#include <vector>

using namespace std;
int linearSearch(vector<int>& a, int n, int x) {
    int i = 0;
    while(i < n && a[i] != x) 
        i++;
        if(i == n)
        return -1;
        return i;
    // int pos = -1;
    // for(int i = 0; i < n; i++) {
    //     if(a[i] == x) {
    //         pos = i;
    //     }
    // }
    // return pos;
}
int main() {
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << linearSearch(v, n, x);
    return 0;
}