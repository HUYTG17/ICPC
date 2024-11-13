#define TGH return 0
#define TG ios_base::sync_with_stdio(false)
#define H cin.tie(nullptr)

#include <iostream>

using namespace std;

int LinearSearch(int a[], int n, int x) {
    int i;
    a[n] = x;
    for(i = 0; i < n && a[i] != x; i++);
    if(i < n) {
        return i;
    }
    return -1;
}
int main() {
    TG; H;
    int n, x; cin >> n >> x;
    int a[n + 1];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << LinearSearch(a, n, x);
    TGH;
}