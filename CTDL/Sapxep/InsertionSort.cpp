// tăng
#include <iostream>
using namespace std;
void insertionSort(int a[], int n) {
    int pos, x;
    for(int i = 1; i < n; i++) {
        x = a[i];
        for(pos = i; (pos > 0) && (a[pos-1] > x); pos--)
            a[pos] = a[pos-1];
        a[pos] = x;
    }
}
int main() {
    int n;
    cin >> n;
    int a[100];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    insertionSort(a, n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
// giảm
#include <iostream>
using namespace std;
void insertionSort(int a[], int n) {
    int pos, x;
    for(int i = 1; i < n; i++) {
        x = a[i];
        for(pos = i; (pos > 0) && (a[pos-1] < x); pos--)
            a[pos] = a[pos-1];
        a[pos] = x;
    }
}
int main() {
    int n;
    cin >> n;
    int a[100];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    insertionSort(a, n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
