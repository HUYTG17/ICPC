// tăng
#include <iostream>
using namespace std;
void BubbleSort(int a[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = n - 1; j > i; j--) {
            if(a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
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
    BubbleSort(a, n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
// giảm
#include <iostream>
using namespace std;
void BubbleSort(int a[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = n - 1; j > i; j--) {
            if(a[j] > a[j-1]) {
                swap(a[j], a[j-1]);
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
    BubbleSort(a, n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}