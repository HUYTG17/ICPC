#include <iostream>
using namespace std;
int linesearch(int a[], int n, int x, int y) {
    int pos = -1;
    int lech = y + 1;
    for(int i = 0; i < n; i++) {
        if(abs(a[i] - x) <= y && abs(a[i] - x) < lech) {
            lech = abs(a[i] - x);
            pos = i;
        } 
    }
    return pos;
}
int main() {
    int n, x, y;
    cin >> n >> x >> y;
    int a[100];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << linesearch(a, n, x, y);
}