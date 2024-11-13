#include <iostream>
#include <vector>
using namespace std;
vector<int> binary_search(int a[], int n, int x) {
    vector<int> v;
    int l = 0, r = n -1, pos = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(a[mid] == x) {
            pos = mid;
            v.push_back(pos);
            l = mid + 1;
        } else if(a[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return v;
}
int main() {
    int n, x; cin >> n >> x;
    int a[100];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == x) {
            cnt++;
        }
    }
    if(cnt == n) {
        for(int i = 0; i < n; i++) {
            cout << i << " ";
        }
    } else {
        vector<int> v = binary_search(a, n, x);
        if(v.empty()) {
            cout << "-1";
        }
        else {
            for(int i : v) {
                cout << i << " ";
            }
        }
    }
}