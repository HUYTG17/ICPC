#include <iostream>
using namespace std;
int linearsearch(int a[], int n, int x) {
    int max = -9999, pos = -1;
    for(int i = 0; i < n; i++) {
        if(max < a[i] && a[i] <= x) {
            max = a[i];
            pos = i;
        }
    }
    return pos;
}
int main() {
    int x, a[100];
    cin >> x;
    int n = 0;
    int m;
    while(cin >> m) {
        a[n++] = m;
    }
    cout << linearsearch(a, n, x);
}