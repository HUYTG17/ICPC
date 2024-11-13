// tăng
#include <iostream>
using namespace std;
void selectionSort(int a[], int n) {
    int min;
    for(int i = 0; i < n; i++) {
        min = i;
        for(int j = i + 1; j < n; j++)
            if(a[j] < a[min])
            min = j;
        if(min != i) {
            swap(a[i], a[min]);
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
    selectionSort(a, n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
//giảm
#include <iostream>
using namespace std;
void selectionSort(int a[], int n) {
    int min;
    for(int i = 0; i < n; i++) {
        min = i;
        for(int j = i + 1; j < n; j++)
            if(a[j] > a[min])
            min = j;
        if(min != i) {
            swap(a[i], a[min]);
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
    selectionSort(a, n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}