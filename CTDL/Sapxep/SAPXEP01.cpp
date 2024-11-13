#define TGH return 0
#define TG ios_base::sync_with_stdio(false)
#define H cin.tie(nullptr)

#include <iostream>
#include <vector>

using namespace std;

void InsertionSortUp(vector<int>& a, int n) {
    int pos, x, i;
    for(int i = 1; i < n; i++) {
        x = a[i];
        for(pos = i; (pos > 0) && (a[pos - 1] > x); pos--)
            a[pos] = a[pos - 1];
        a[pos] = x;
    }
}
void InsertionSortDown(vector<int>& a, int n) {
    int pos, x, i;
    for(int i = 1; i < n; i++) {
        x = a[i];
        for(pos = i; (pos > 0) && (a[pos - 1] < x); pos--)
            a[pos] = a[pos - 1];
        a[pos] = x;
    }
}

int main() {
    TG; H;
    int n; cin >> n;
    vector<int> v1(n);
    vector<int> v2;
    vector<int> v3;
    for(int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for(int i = 0; i < n; i++) {
        if(i < (n + 1) / 2) {
            v2.push_back(v1[i]);
        } else {
            v3.push_back(v1[i]);
        }
    }
    InsertionSortUp(v2, v2.size());
    InsertionSortDown(v3, v3.size());
    for(const auto& p : v2) {
        cout << p << " ";
    }
    for(const auto& p : v3) {
        cout << p << " ";
    }
    TGH;
}