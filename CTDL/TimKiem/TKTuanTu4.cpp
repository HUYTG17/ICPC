#include <iostream>
#include <vector>
using namespace std;
int timmax(int a[], int n, int x) {
    int max = -99999;
    for(int i = 0; i < n; i++) {
        if(max < a[i] && a[i] <= x) max = a[i];
    }
    return max;
}
vector<int> linearsearch(int a[], int n, int x) {
    int max = timmax(a, n, x);
    vector<int> v;
    for(int i = 0; i < n; i++) {
        if(max == a[i]) {
            v.push_back(i);
        }
    }
    return v;
}
int main() {
    int n = 0, x;
    cin >> x;
    int m, a[100];
    while(cin >> m) {
        a[n++] = m;
    }
    vector<int> v = linearsearch(a, n, x);
    if(v.empty()) {
        cout << -1;
    } else {
        for(int i : v) {
            cout << i << " ";
        }
    }
}