#define ll long long
#define PI 3.14159

#define EPS 1e-4

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // i <= bi*Ri^2 / ans <= F + 1
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, f, r[10005];
        cin >> n >> f;
        for(int i = 0; i < n; i++)
            cin >> r[i];
        double lo = PI, hi = PI * 1e8;
        while(abs(lo - hi) >= EPS) {
            double mid = (lo + hi) / 2;
            int dem = 0;
            for(int i = 0; i < n; i++) {
                dem += (int)((PI * r[i] * r[i]) / mid);
            }
            if(dem < f + 1) hi = mid;
            else lo = mid;
        }
        printf("%.4f\n", lo);
    }
    return 0;
}