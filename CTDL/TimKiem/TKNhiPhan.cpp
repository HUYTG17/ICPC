#include <iostream>
using namespace std;
int binary_search(int a[], int n, int x) {
    int l = 0, r = n - 1, pos = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(a[mid] == x) {
            pos = mid;
            r = mid - 1;
        } else if(a[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return pos;
}

int main() {
    int n, x;
    cin >> n >> x;
    int a[100];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << binary_search(a, n, x);
}