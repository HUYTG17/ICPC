#define ll long long
#define TG ios::sync_with_stdio(false)
#define H cin.tie(0)

#include <iostream>

using namespace std;

const int inf = 1e9 + 7;
const int maxN = 1e5 + 7;
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
    if(!lazy[id]) return;
    st[id] += lazy[id];
    
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

int main()
{
    TG; 
    H;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    cin >> q;
    while(q--) 
    {
        ll type, l, r, val;
        cin >> type >> l >> r;
        if(type == 1)
        {
            cin >> val;
            update(1, 1, n, l, r, val);
        }
        else cout << get(1, 1, n, l, r) << '\n';
    }
    return 0;
}

/*
if(!lazy[id]) return;
st[id] += lazy[id] * [r - l + 1];
if(l != r)
{
    lazy[2 * id] += lazy[id];
    lazy[2* id + 1] += lazy[id];
}
lazy[id] = 0;
*/


#include <bits/stdc++.h> 
 
using namespace std ;
 
#define ll long long 
#define Takamiya ios_base::sync_with_stdio(false)
#define Shinji cin.tie (nullptr)
#define Shido cout.tie(nullptr)
 
const ll maxN = 2e5 + 7 ;
const ll inf = 1e9 + 7 ; 
 
ll a[maxN] ;
ll st[4 * maxN] ;
ll lazy [4 * maxN] ; 
 
void build(ll id, ll l, ll r) {
    if (l == r) {
        st[id] = a[l];
    } else {
        ll mid = (l + r) / 2;
        build(id * 2, l, mid);              
        build(id * 2 + 1, mid + 1, r);       
        st[id] = max(st[id * 2], st[id * 2 + 1]);   
    }
}
 
void fix(ll id, ll l, ll r) {
    if (!lazy[id]) return;
    st[id] += lazy[id];  
    if (l != r) {
        lazy[id * 2] += lazy[id];         
        lazy[id * 2 + 1] += lazy[id];     
    }
    lazy[id] = 0; 
}
 
ll get(ll id, ll l, ll r, ll u, ll v) {
    fix(id, l, r);  
    if (l > v || r < u) return -1e18; 
    if (l >= u && r <= v) return st[id]; 
    ll mid = (l + r) / 2;
    ll leftMax = get(id * 2, l, mid, u, v);       
    ll rightMax = get(id * 2 + 1, mid + 1, r, u, v); 
    
    return max(leftMax, rightMax);
}
 
void update(int id, int l, int r, int u, int v, int val) {
    fix(id, l, r);  
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        lazy[id] += val;  
        fix(id, l, r); 
        return;
    }
    int mid = (l + r) / 2;
    update(2 * id, l, mid, u, v, val);
    update(2 * id + 1, mid + 1, r, u, v, val);
    st[id] = max(st[2 * id], st[2 * id + 1]); 
}
int main() {
    ll n, q, l, r, k;
    cin >> n >> q;
    for (ll i = 1; i <= n; ++i)
        cin >> a[i];
    build(1, 1, n); 
    while (q--) {
        cin >> k;
        if (k == 1) {
            cin >> l >> r >> k;  
            update(1, 1, n, l, r, k);
    
        } 
        else {
            cin >> l;
            cout << get(1, 1, n, l, l) << '\n';
        }
    }
    return 0;
}