#define TG ios::sync_with_stdio(false)
#define H cin.tie(0)
#define ll long long 

#include <iostream>

using namespace std;

const int maxN = 1e6 + 7; // 1e5 k du xai 1e6
ll n, q;
int a[maxN];
ll st[4 * maxN];

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
    st[id] = st[2 * id] ^ st[2 * id + 1];
}

ll get(ll id, ll l, ll r, ll u, ll v)
{
    if(l > v || r < u) return 0;
    if(l >= u && r <= v) return st[id];
    ll mid = (l + r) >> 1;
    ll a = get(2 * id, l, mid, u , v);
    ll b = get(2 * id + 1, mid + 1, r, u, v);
    return a ^ b;
}

int main()
{
    TG;
    H;
    cin >> n >> q;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(q--)
    {
        ll a, b;
        cin >> a >> b;
        cout << get(1, 1, n, a, b) << '\n';
    }
    return 0;
}