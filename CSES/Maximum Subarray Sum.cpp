#define ll long long

#include <vector>
#include <iostream>
using namespace std;

void M_sa_sum(vector<ll>& a) {
    ll current_sum = a[0];
    ll max_sum = a[0];
    for(int i = 1; i < a.size(); i++) {
        current_sum = max(a[i], current_sum + a[i]);
        max_sum = max(current_sum, max_sum);
    }
    cout << max_sum;
}

void Input(int n, vector<ll>& a) {
    for(int i = 0; i < n; i++) cin >> a[i];
}
int main() {
    int n; cin >> n;
    vector<ll> a(n);
    Input(n, a);
    M_sa_sum(a);
}