#define TGH return 0
#define TG ios_base::sync_with_stdio(false)
#define H cin.tie(nullptr)

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
void BubbleSort(char a[], int n, char c) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = n - 1; j > i; j--) {
            if(c == 'A') {
                if(a[j] < a[j - 1]) {
                    swap(a[j], a[j - 1]);
                }
            } else {
                if(a[j] > a[j - 1]) {
                    swap(a[j], a[j - 1]);
                }
            }
        }
    }
}

void Input(char a[], int n) {
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void Output(char a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    TG; H;
    char c; int n; char *a = new char[n];
    cin >> c >> n;
    Input(a, n);
    BubbleSort(a, n, c);
    Output(a, n);
    TGH;
}