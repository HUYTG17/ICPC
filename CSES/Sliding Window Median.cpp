#define TGH return 0
#define TG ios_base::sync_with_stdio(false)
#define G cin.tie(nullptr)
#define H cout.tie(nullptr)
#define fi first

#include <iostream>
#include <set>

using namespace std;

typedef pair<int, int> pii;
const int MAXN = 2e5 + 1;
int n, k;
int x[MAXN];

void solve(multiset<pii>& left, multiset<pii>& right) {
    int size = (k + 1) / 2;
    while(int(left.size()) < size) {
        pii p = *right.begin();
        left.insert(p);
        right.erase(p);
    }
    while(int(left.size()) > size) { // 2 3 
        pii p = *left.rbegin();
        right.insert(p); // 4
        left.erase(p);
    }
}

int main() {
    TG; G; H;
    multiset<pii> left, right;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    if(k == 1) {
        for(int i = 0; i < n; i++) {
            cout << x[i] << ' ';
        }
        return 0;
    } else if(k == 2) {
        for(int i = 1; i < n; i++) {
            cout << min(x[i - 1], x[i]) << ' ';
        }
        return 0;
    }
    for(int i = 0; i < k; i++) {
        left.insert({x[i], i}); // 2 4 3
    }
    solve(left, right);
    cout << rbegin(left)->fi << ' ';
    for(int i = 1; i < n - k + 1; ++i) {
        pii temp = {x[i - 1], i - 1}; // 2 // 4 // 3 // 5 // 8
        if(left.count(temp)) left.erase(left.find(temp)); //1 1 
        else if(right.count(temp)) right.erase(right.find(temp)); 
        int pos = i + k - 1; // 3 // 4 // 5 // 6 // 7
        pii next = {x[pos], pos}; // 5 // 8 // 1 // 2 // 1
        if(x[pos] <= left.rbegin()->fi) { 
            left.insert(next);
        } else {
            right.insert(next); // 
        }
        solve(left, right);
        cout << left.rbegin()->fi << ' '; // 4 // 5 // 5 // 2
    }
    TGH;
}
