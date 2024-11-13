#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define ifile freopen("inp.txt", "r", stdin)
#define ofile freopen("out.txt", "w", stdout)
#define setup(a, c) memset(a, c, sizeof(a))
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FOD(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define rz resize
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int timKiem (int a[], int n, int x) {
    vector<int> list_index;
    FOR(i, 0, n - 1) {
        if (a[i] == x) {
            list_index.pb(i);
        }
    }
    if (!list_index.empty()) {
        cout << "Tat ca vi tri xuat hien: ";
        for (const int& index : list_index) {
            cout << index << ' ';
        }
        return 1;
    }
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ifile; ofile;
    int n, x;
    int a[100];
    cin >> n >> x;
    FOR(i, 0, n - 1) {
        cin >> a[i];
    }
    if (!timKiem(a, n, x)) {
        cout << "Khong tim thay";
    }
    cerr << "\nProgram Executed Successfully!\n";
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}