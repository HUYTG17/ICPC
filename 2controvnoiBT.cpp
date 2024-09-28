#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    vector<ll> v1(n);
    vector<ll> v2(n);
    ll minkq = LLONG_MAX;
    for(int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> v2[i];
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int j = n - 1, i = 0;
    while(i < n && j >= 0) {
        ll sum = v1[i] + v2[j];
        minkq = min(minkq, abs(sum));
        if(sum == 0) {
            break;
        }
        if(sum > 0) {
            j--;
        }
        else {
            i++;
        }
    }
    cout << minkq;
    return 0;
}