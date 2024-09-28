
#define TGH return 0
#define TG ios_base::sync_with_stdio(false)
#define G cin.tie(nullptr)
#define H cout.tie(nullptr)
#define ll long long

#include <bits/stdc++.h>

using namespace std;

struct Range {
    int x, y, index;
    bool contain = 0, contained = 0;
};

bool cmp(const Range& a, const Range& b) {
    if(a.x != b.x) return a.x < b.x;
    return a.y > b.y;
}

int main() {
    TG; G; H;
    ll n; cin >> n;
    vector<Range> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
        v[i].index = i;
    }
    sort(v.begin(), v.end(), cmp);
    int min_y = INT_MAX;
    for(int i = n - 1; i >= 0; i--) {
        if(v[i].y >= min_y) {
            v[i].contain = 1;
        }
        min_y = min(min_y, v[i].y);
    }
    int max_y = -1;
    for(auto& r : v) {
        if(r.y <= max_y) {
            r.contained = 1;
        }
        max_y = max(max_y, r.y);
    }
    vector<int> vc(n), vcd(n);
    for(auto& r : v) {
        vc[r.index] = r.contain;
        vcd[r.index] = r.contained;
    }
    for(int i : vc) {
        cout << i << ' ';
    }
    cout << '\n';
    for(int j : vcd) {
        cout << j << ' ';
    }
    TGH;
}
