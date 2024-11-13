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

int tkNhiPhan (int a[], int n, int x, int &i) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + r >> 1;
        if (a[m] == x) {
            return m;
        }
        else if (a[m] > x) {
            i++;
            r = m - 1;
        }
        else {
            i++;
            l = m + 1;
        }
    }
    return -1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ifile; ofile;
    int n, x, count = 0;
    int a[100];
    cin >> n >> x;
    FOR(i, 0, n - 1) {
        cin >> a[i];
    }
    if (tkNhiPhan(a, n, x, count) == -1) {
        cout << "Khong tim thay";
    }
    else {
        cout << "So lan chia doi cua mang: " << count << '\n';
        int l = 0, r = n - 1, j = 1;
        while (l <= r) {
            int m = l + r >> 1;
            if (a[m] == x) break;
            else {
                cout << "Lan " << j++ << ": x = " << x << " nam trong doan [";
                if (a[m] > x) {
                    cout << l << ".." << m - 1;
                    r = m - 1;
                }
                else {
                    cout << m + 1 << ".." << r;
                    l = m + 1;
                }
                    cout << "]" << " // mid = " << m << '\n';
            }
        }
    }
    cerr << "\nProgram Executed Successfully!\n";
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}