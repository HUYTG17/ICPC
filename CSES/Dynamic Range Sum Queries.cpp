#define ll long long
#include <iostream>

using namespace std;

const ll Max = 1e6 + 7;

ll st[Max * 4], a[Max];

void build(ll id, ll l, ll r) {
    if(l == r) {
        st[id] = a[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

void update(ll id, ll l, ll r, ll pos, ll val) {
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

ll get(ll id, ll l, ll r, ll u, ll v) {
    if(l > v || r < u) return 0;
    if(l >= u && r <= v) return st[id];
    ll mid = (l + r) / 2;
    ll a = get(id * 2, l, mid, u, v);
    ll b = get(id * 2 + 1, mid + 1, r, u, v);
    return a + b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    ll n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while(q--) {
        ll type, x, y;
        cin >> type >> x >> y;
        if(type == 1) update(1, 1, n, x, y);
        else cout << get(1, 1, n, x, y) << '\n';
    }
    return 0;
}