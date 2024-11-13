#include <iostream>
#include <vector>
using namespace std;
vector<int> linearsearch(int a[], int n, int x) {
    vector<int> v;
    for(int i = 0; i < n; i++) {
        if(a[i] == x) {
            v.push_back(i);
        }
    }
    return v;
}
int main() {
    int n, x; cin >> n >> x;
    int a[100];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> v = linearsearch(a, n, x);
    if(v.empty()) {
        cout << "-1";
    } else { 
        for(int i : v) {
            cout << i << " ";
        }
    }
}