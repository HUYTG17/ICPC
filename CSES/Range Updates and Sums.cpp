#define ll long long
#define TG ios::sync_with_stdio(false)
#define H cin.tie(0)

#include <iostream>

using namespace std;

const int inf = 1e9 + 7;
const int maxN = 1e6 + 7;
ll n, q;
int a[maxN];
ll st[4 * maxN], lazy[4 * maxN], lazy2[4 * maxN];

void build(ll id, ll l, ll r)
{
    if(l == r)
    {
        st[id] = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id] = (st[2 * id] + st[2 * id + 1]);
}

void fix(ll id, ll l, ll r)
{
    if(lazy2[id])
    {
        st[id] = lazy2[id] * (r - l + 1);
        lazy2[2 * id] = lazy2[id];
        lazy2[2 * id + 1] = lazy2[id];
        lazy[2 * id] = 0;
        lazy[2 * id +1] = 0;
    }
    lazy2[id] = 0;
    
    if(!lazy[id]) return;
    st[id] += lazy[id] * (r - l + 1);
    if(l != r)
    {
        lazy[2 * id] += lazy[id];
        lazy[2 * id + 1] += lazy[id];
    }
    lazy[id] = 0;
}

void update(ll id, ll l, ll r, ll u, ll v, ll val)
{
    fix(id, l, r);
    if(l > v || r < u) return;
    if(l >= u && r <= v)
    {
        lazy[id] += val;
        fix(id, l, r);
        return;
    }
    ll mid = (l + r) >> 1;
    update(2 * id, l, mid, u, v, val);
    update(2 * id + 1, mid + 1, r, u, v, val);
    st[id] = (st[2 * id] + st[2 * id + 1]);
}

void update2(ll id, ll l, ll r, ll u, ll v, ll val)
{
    fix(id, l, r);
    if(l > v || r < u) return;
    if(l >= u && r <= v)
    {
        lazy2[id] = val;
        fix(id, l, r);
        return;
    }
    ll mid = (l + r) >> 1;
    update2(2 * id, l, mid, u, v, val);
    update2(2 * id + 1, mid + 1, r, u, v, val);
    st[id] = (st[2 * id] + st[2 * id + 1]);
}

ll get(ll id, ll l, ll r, ll u, ll v)
{
    fix(id, l, r);
    if(l > v || r < u) return 0;
    if(l >= u && r <= v) return st[id]; 
    ll mid = (l + r) >> 1;
    ll a = get(2 * id, l, mid, u, v);
    ll b = get(2 * id + 1, mid + 1, r, u, v);
    return a + b;
}


int main()
{
    TG;
    H;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(q--)
    {
        ll type, a, b, x;
        cin >> type >> a >> b;
        if(type == 1)
        {
            cin >>  x;
            update(1, 1, n, a, b, x);
        }
        else if(type == 2)
        {
            cin >> x;
            update2(1, 1, n, a, b, x);
        }
        else 
        {
            cout << get(1, 1, n, a, b) << '\n';
        }
    }
    return 0;
}


/*
#include <bits/stdc++.h>

using namespace std;

const int mod  = 1e9 + 7;
const int maxN = 1e5 + 7;

int n, m;
int st[4 * maxN];
pair <int, int> lazy[4 * maxN];

void fix(int id, int l, int r) {
    int a = lazy[id].first;
    int b = lazy[id].second;
    st[id] += (1ll * a * (r + l) * (r - l + 1) / 2) % mod;
    st[id] %= mod;
    st[id] += (1ll * b * (r - l + 1)) % mod;
    st[id] %= mod;

    if (l != r) {
        lazy[2 * id].first  = (lazy[2 * id].first  + a) % mod;
        lazy[2 * id].second = (lazy[2 * id].second + b) % mod;
        lazy[2 * id + 1].first  = (lazy[2 * id + 1].first  + a) % mod;
        lazy[2 * id + 1].second = (lazy[2 * id + 1].second + b) % mod;
    }
    lazy[id] = {0, 0};
}

void update(int id, int l, int r, int u, int v, int a, int b) {
    fix(id, l, r);
    if (l >  v || r <  u) return;
    if (l >= u && r <= v) {
        lazy[id].first  = a;
        lazy[id].second = (1ll * b - 1ll * u * a + 1ll * mod * mod) % mod;
        fix(id, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(2 * id, l, mid, u, v, a, b);
    update(2 * id + 1, mid + 1, r, u, v, a, b);
    st[id] = (st[2 * id] + st[2 * id + 1]) % mod;
}

int get(int id, int l, int r, int u, int v) {
    fix(id, l, r);
    if (l >  v || r <  u) return 0;
    if (l >= u && r <= v) return st[id];

    int mid  = l + r >> 1;
    int get1 = get(2 * id, l, mid, u, v);
    int get2 = get(2 * id + 1, mid + 1, r, u, v);
    return (get1 + get2) % mod;
}

int main() {
    cin >> n >> m;
    while (m--) {
        int type, l, r, a, b;
        cin >> type >> l >> r;
        if (type == 1) {
            cin >> a >> b;
            update(1, 1, n, l, r, a, b);
        }
        else cout << get(1, 1, n, l, r) << '\n';
    }
}
*/