#include <iostream>
using namespace std;
int LinearSearch(int a[], int n, int x) {
    int i = 0;
    while(i < n && a[i] != x)
        i++;
        if(i == n) 
        return -1;
        return i;
}
int main() {
    int n, x, a[100];
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << LinearSearch(a, n, x);
}
