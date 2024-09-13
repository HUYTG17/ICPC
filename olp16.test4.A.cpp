#define TGH return 0
#define TG ios_base::sync_with_stdio(false)
#define H cin.tie(nullptr)

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    TG; H;
    int n; cin >> n;
    vector<long long> v1(n + 1, LLONG_MIN);
    vector<long long> v2(n + 1, LLONG_MIN);
    for(int i = 1; i <= n; i++) {
        cin >> v1[i];
    }
    long long maxF = LLONG_MIN;
    long long maxV = LLONG_MIN;
    v2[n] = 3 * v1[n];
    for(int i = n - 1; i >= 1; i--) {
        v2[i] = max(v2[i + 1], 3 * v1[i]);
    }
    for(int i = 2; i <= n - 1; i++) {
        maxV = max(maxV, v1[i - 1]);
        maxF = max(maxF, maxV + 2 * v1[i] + v2[i + 1]);
    }
    cout << maxF;
    TGH;
}