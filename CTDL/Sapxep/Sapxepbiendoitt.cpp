// tang
#include <iostream>
using namespace std;
void sxbdtr(int a[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[i]) {
                swap(a[j], a[i]);
            }
        }
    }
}
int main() {
    int n;
    cin >> n;
    int a[100];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sxbdtr(a, n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
// giảm
#include <iostream>
using namespace std;
void sxbdtr(int a[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[j] > a[i]) {
                swap(a[j], a[i]);
            }
        }
    }
}
int main() {
    int n;
    cin >> n;
    int a[100];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sxbdtr(a, n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}