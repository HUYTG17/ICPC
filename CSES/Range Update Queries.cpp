/*#define ll long long
#define TG ios::sync_with_stdio(false)
#define H cin.tie(0)

#include <iostream>

using namespace std;

const int inf = 1e9 + 7;
const int maxN = 1e6 + 7;
ll n, q;
int a[maxN];
ll st[4 * maxN], lz[4 * maxN];

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
    st[id] = max(st[2 * id], st[2 * id + 1]);
}

void fix(ll id, ll l, ll r)
{
    if(!lz[id]) return;
    st[id] += lz[id];
    if(l != r)
    {
        lz[2 * id] += lz[id];
        lz[2 * id + 1] += lz[id];
    }
    lz[id] = 0;
}

void update(ll id, ll l, ll r, ll u, ll v, ll val)
{
    fix(id, l, r);
    if(l > v || r < u) return;
    if(l >= u && r <= v)
    {
        lz[id] += val;
        fix(id, l, r);
        return;
    }
    ll mid = (l + r) >> 1;
    update(2 * id, l, mid, u, v, val);
    update(2 * id + 1, mid + 1, r, u, v, val);
    st[id] = max(st[2 * id], st[2 * id + 1]);
}

ll get(ll id, ll l, ll r, ll u, ll v)
{
    fix(id, l, r);
    if(l > v || r < u) return -inf;
    if(l >= u && r <= v) return st[id]; 
    ll mid = (l + r) >> 1;
    ll a = get(2 * id, l, mid, u, v);
    ll b = get(2 * id + 1, mid + 1, r, u, v);
    return max(a, b);
}
// or
/*
ll get(ll id, ll l, ll r, ll pos)
{
    fix(id, l, r);
    if(l == r) return st[id]; 
    ll mid = (l + r) >> 1;
    if(pos <= mid) return get(2 * id, l, mid, pos);
    else return get(2 * id + 1, mid + 1, r, pos);
}


*/


/*int main()
{
    TG;
    H;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(q--)
    {
        ll type, l, r, val;
        cin >> type;
        if(type == 1)
        {
            cin >>  l >> r >> val;
            update(1, 1, n, l, r, val);
        }
        else 
        {
            cin >> l;   
            cout << get(1, 1, n, l, l) << '\n';
        }
    }
    return 0;
}
*/
#define ll long long
#define TG ios::sync_with_stdio(false)
#define H cin.tie(0)

#include <iostream>

using namespace std;

const int inf = 1e9 + 7;
const int maxN = 1e6 + 7;
ll n, q;
int a[maxN];
ll st[4 * maxN], lazy[4 * maxN];

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
    st[id] = max(st[2 * id], st[2 * id + 1]);
}

void fix(ll id, ll l, ll r)
{
    
    if(lazy[id]) {
        st[id] += lazy[id] * (r - l + 1);
        if(l != r)
        {
            lazy[2 * id] += lazy[id];
            lazy[2 * id + 1] += lazy[id];
        }
        lazy[id] = 0;
    }
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
    st[id] = max(st[2 * id], st[2 * id + 1]);
}

ll get(ll id, ll l, ll r, ll pos)
{
    fix(id, l, r);
    if(l == r) return st[id]; 
    ll mid = (l + r) >> 1;
    if(pos <= mid) return get(2 * id, l, mid, pos);
    else return get(2 * id + 1, mid + 1, r, pos);
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
        ll type, a, b, u, pos;
        cin >> type;
        if(type == 1)
        {
            cin >> a >> b >> u;
            update(1, 1, n, a, b, u);
        }
        else 
        {
            cin >> pos;
            cout << get(1, 1, n, pos) <<'\n';
        }
    }
    return 0;
}


/*#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define Takamiya ios_base::sync_with_stdio(false)
#define Shinji cin.tie(nullptr)
#define Shido cout.tie(nullptr)
 
const ll maxN = 2e5 + 7;
const ll inf = 1e9 + 7;
 
int n, q;
int a[maxN];
long long st[4 * maxN], lazy[4 * maxN], lazy2[4 * maxN]; 
 
void build(int id, int l, int r) {
    lazy2[id] = -1; 
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id] = st[2 * id] + st[2 * id + 1];
}
 
void fix(int id, int l, int r) {
    if (lazy2[id] != -1) { 
        st[id] = (r - l + 1) * lazy2[id]; 
        if (l != r) { 
            lazy2[2 * id] = lazy2[id];
            lazy2[2 * id + 1] = lazy2[id];
            lazy[2 * id] = 0; 
            lazy[2 * id + 1] = 0;
        }
        lazy2[id] = -1;
    }
    
    if (lazy[id]) {
        st[id] += lazy[id] * (r - l + 1); 
        if (l != r) {
            lazy[2 * id] += lazy[id];
            lazy[2 * id + 1] += lazy[id];
        }
        lazy[id] = 0;
    }
}
 
void update(int id, int l, int r, int u, int v, int val) {
    fix(id, l, r);
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        lazy[id] += val;
        fix(id, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(2 * id, l, mid, u, v, val);
    update(2 * id + 1, mid + 1, r, u, v, val);
    st[id] = st[2 * id] + st[2 * id + 1];
}
 
void update2(int id, int l, int r, int u, int v, int x) {
    fix(id, l, r);
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        lazy2[id] = x; 
        fix(id, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update2(2 * id, l, mid, u, v, x);
    update2(2 * id + 1, mid + 1, r, u, v, x);
    st[id] = st[2 * id] + st[2 * id + 1];
}
 
long long get(int id, int l, int r, int u, int v) {
    fix(id, l, r);
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return st[id];
 
    int mid = (l + r) >> 1;
    long long get1 = get(2 * id, l, mid, u, v);
    long long get2 = get(2 * id + 1, mid + 1, r, u, v);
    return get1 + get2;
}
 
int main() {
    Takamiya;
    Shinji;
    Shido;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    while (q--) {
        int type, l, r, x;
        cin >> type >> l >> r;
        if (type == 1) {
            cin >> x;
            update(1, 1, n, l, r, x);
        }
        else if (type == 2) {
            cin >> x;
            update2(1, 1, n, l, r, x);
        }
        else cout << get(1, 1, n, l, r) << '\n';
    }
    return 0;
}*/