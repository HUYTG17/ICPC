#include <iostream>
using namespace std;
void linearsearch(int a[], int n, int x) {
    int firstpos = -1, lastpos = -1, max = -9999;
    for(int i = 0; i < n; i++) {
        if(a[i] == x && firstpos == -1) {
            firstpos = i;
        }
        if(max <= a[i] && a[i] < x) {
            max = a[i];
            lastpos = i;
        }
    }
    if(firstpos != -1) {
        cout << "Y\n" << firstpos;
    } else {
        if(lastpos != -1) {
            cout << "N\n" << lastpos;
        } else {
            cout << "N\n" << -1;
        }
    }
}
int main() {
    int n, x, a[100];
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    linearsearch(a, n, x);
}