#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& a, int n) {
    int max;
    for(int i = n - 1; i > 0; i--) {
        max = i;
        for(int j = i - 1; j >= 0; j--) // chay tu 0 thi tim min
            if(a[max] > a[j])
                max = j;
        if(max != i)
            swap(a[max], a[i]);
            for(int i = 0; i < n; i++) {
                cout << a[i] << ' ';
                if(i == n - 1) {
                    cout << endl;
                }
            }
    }
}

void Input(vector<int>& a, int n) {
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void Output(vector<int>& a, int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    Input(a, n);
    selectionSort(a, n);
    
}
/*1 3 4 8 2 19 29 5 9 14
B1 1 3 4 8 2 19 14 5 9 29
B2 1 3 4 8 2 9 14 5 19 29
B3 1 3 4 8 2 9 5 14 19 29
B4 1 3 4 8 2 5 9 14 19 29
B5 1 3 4 5 2 8 9 14 19 29 
B6 1 3 4 2 5 8 9 14 19 29
B7 1 3 2 4 5 8 9 14 19 29
B8 1 2 3 4 5 8 9 14 19 29
B9 1 2 3 4 5 8 9 14 19 29
*/

/*1 3 4 8 2 19 29 5 9 14 
B1 14 3 4 8 2 19 29 5 9 1
B2 14 3 4 8 9 19 29 5 2 1
B3 14 5 4 8 9 19 29 3 2 1
B4 14 5 29 8 9 19 4 3 2 1
B5 14 19 29 8 9 5 4 3 2 1
B6 14 19 29 9 8 5 4 3 2 1
B7 14 19 29 9 8 5 4 3 2 1
B8 29 19 14 9 8 5 4 3 2 1
B9 29 19 14 9 8 5 4 3 2 1
*/

#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& a, int n) {
    int pos, x;
    for(int i = n - 2; i >= 0; i--) {
        x = a[i];
        for(pos = i; (pos < n - 1) && (a[pos + 1] > x); pos++)
            a[pos] = a[pos + 1];
        a[pos] = x;
        
        
        for(int i = 0; i < n; i++) {
            cout << a[i] << ' ';
            if(i == n - 1) {
                cout << endl;
            }
        }
    }
}
/* 1 3 4 8 2 19 29 5 9 14
B1 1 3 4 8 2 19 29 5 14 9
B2 1 3 4 8 2 19 29 14 9 5
B3 1 3 4 8 2 19 29 14 9 5
B4 1 3 4 8 2 29 19 14 9 5
B5 1 3 4 8 29 19 14 9 5 2
B6 1 3 4 29 19 14 9 8 5 2
B7 1 3 29 19 14 9 8 5 4 2
B8 1 29 19 14 9 8 5 4 3 2
B9 29 19 14 9 8 5 4 3 2 1
*/
/*1 3 4 8 2 19 29 5 9 14
B1 1 3 4 8 2 19 29 5 9 14
B2 1 3 4 8 2 19 29 5 9 14
B3 1 3 4 8 2 19 5 9 14 29
B4 1 3 4 8 2 5 9 14 19 29
B5 1 3 4 8 2 5 9 14 19 29
B6 1 3 4 2 5 8 9 14 19 29
B7 1 3 2 4 5 8 9 14 19 29
B8 1 2 3 4 5 8 9 14 19 29
B9 1 2 3 4 5 8 9 14 19 29
*/
/*1 3 4 8 2 19 29 5 9 14
B1 1 3 4 8 2 19 29 5 9 14
B2 1 3 4 8 2 19 29 5 9 14
B3 1 3 4 8 2 19 29 5 9 14
B4 1 2 3 4 8 19 29 5 9 14
B5 1 2 3 4 8 19 29 5 9 14
B6 1 2 3 4 8 19 29 5 9 14
B7 1 2 3 4 5 8 19 29 9 14
B8 1 2 3 4 5 8 9 19 29 14
B9 1 2 3 4 5 8 9 14 19 29
*/
/*1 3 4 8 2 19 29 5 9 14
B1 3 1 4 8 2 19 29 5 9 14
B2 4 3 1 8 2 19 29 5 9 14
B3 8 4 3 1 2 19 29 5 9 14
B4 8 4 3 2 1 19 29 5 9 14
B5 19 8 4 3 2 1 29 5 9 14
B6 29 19 8 4 3 2 1 5 9 14
B7 29 19 8 5 4 3 2 1 9 14
B8 29 19 9 8 5 4 3 2 1 14
B9 29 19 14 9 8 5 4 3 2 1
*/
void Input(vector<int>& a, int n) {
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void Output(vector<int>& a, int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    Input(a, n);
    insertionSort(a, n);
    
}
/*1 3 4 8 2 19 29 5 9 14
B1 1 3 4 8 2 19 14 5 9 29
B2 1 3 4 8 2 9 14 5 19 29
B3 1 3 4 8 2 9 5 14 19 29
B4 1 3 4 8 2 5 9 14 19 29
B5 1 3 4 5 2 8 9 14 19 29 
B6 1 3 4 2 5 8 9 14 19 29
B7 1 3 2 4 5 8 9 14 19 29
B8 1 2 3 4 5 8 9 14 19 29
B9 1 2 3 4 5 8 9 14 19 29
*/

/*1 3 4 8 2 19 29 5 9 14 
B1 14 3 4 8 2 19 29 5 9 1
B2 14 3 4 8 9 19 29 5 2 1
B3 14 5 4 8 9 19 29 3 2 1
B4 14 5 29 8 9 19 4 3 2 1
B5 14 19 29 8 9 5 4 3 2 1
B6 14 19 29 9 8 5 4 3 2 1
B7 14 19 29 9 8 5 4 3 2 1
B8 29 19 14 9 8 5 4 3 2 1
B9 29 19 14 9 8 5 4 3 2 1
*/