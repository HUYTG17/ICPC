#define ll long long
#include <iostream>

using namespace std;

const ll Max = 1e6 + 7;

ll st[Max * 4], a[Max], b[Max];

void build(ll id, ll l, ll r) {
    if(l == r) {
        st[id] = a[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

void update(ll id, ll l, ll r, ll pos, ll val) {
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] = val;
        return;
    }
    ll mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

ll get(ll id, ll l, ll r, ll u, ll v) {
    if(l > v || r < u) return 0;
    if(l >= u && r <= v) return st[id];
    ll mid = (l + r) / 2;
    ll a = get(id * 2, l, mid, u, v);
    ll b = get(id * 2 + 1, mid + 1, r, u, v);
    return max(a + b);
}
/*void find(ll id, ll l, ll r, ll val) {
    if(l == r) {
        cout << l << ' ';
        st[id] -= val;
        a[id] -= val;
    }
    else {
        int mid = (l + r) / 2;
        if(st[id * 2] >= val) 
            find(id * 2, l, mid, val);
        else 
            find(id * 2 + 1, l, mid + 1, val);
        
        st[id] = max(st[2 * id], st[2 * id + 1]);
    }
}*/
void find(ll id, ll l, ll r, ll val) {
    if(l == r) {
        cout << a[l] << ' ';
        st[id] = 0;
        b[l] = 0;
    }
    else {
        int mid = (l + r) / 2;
        if(st[id * 2] >= val)
            find(id * 2, l, mid, val);
        else 
            find(id * 2 + 1, mid + 1, r, val - st[id * 2]);
        st[id] = st[id * 2] + st[2 * id + 1];
    }
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
    for(int i = 1; i < q; i++) {
        cin >> b[i];
        find(id, l, r, b[i]);

    }
    
    return 0;
}



/*5
2 6 1 4 2
3 1 3 1 1

6 4 

1 2 2 6 4

*/