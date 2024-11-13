#include <iostream>
using namespace std;
float tong(int *a, int n) {
    float s = 0;
    for(int i = 0; i < n; i++) {
        s += a[i];
    }
    return s;
}
int main () {
    int n;
    cin >> n;
    int *a = new int [n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    float s1 = tong(a, n);
    cout << s1;
}