#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m), c;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int i = 0, j = 0;
    while(i < n || j < m) {
        if(j == m || i < n && a[i] <= b[j]) { // j == m
                                              // a = [1, 3, 5]
                                              // b = [2, 4]
                                                
            c.push_back(a[i++]);
        }
        else {
            c.push_back(b[j++]);
        }
    }
    for(int i : c) {
        cout << i << ' ';
    }
}