#define ll long long

#include <iostream>
#include <cmath>

using namespace std;

int n, t = 1;
ll l, r;

int main() {
    // x^k <= R --> R ^ 1/K
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    while(n--) {
        cin >> l >> r;
        int ans = 1;
        int lo, hi, mid;
        for(int k = 40; k > 0; k--) {
            lo = 1;
            hi = pow(r, (float)1 / k);
            while(lo <= hi) {
                mid = lo + (hi - lo) / 2;
                ll lt = pow(mid, k);
                if(lt >= l && lt <= r) {
                    ans = k;
                    break;
                }
                else if(lt < l) lo = mid + 1;
                else if(lt > r) hi = mid;
                cout << lo << ' ' << hi << ' ' << mid << '\n';
            }
            if(ans > 1) break;
        }
        cout << "Case #" << t << ": " << ans << '\n';
        t++;
    }
}