#define TGH return 0
#define TG ios_base::sync_with_stdio(false)
#define H cin.tie(nullptr)
#include <iostream>
#include <vector>
using namespace std;
long long Tribonacci(long long n) {
    vector<long long> v(1000000, 0);
    v[0] = v[1] = 0;
    v[2] = 1;
    for(int i = 3; i <= 100; i++) {
        v[i] = v[i - 1] + v[i - 2] + v[i - 3];
    }
    for(int i = 0; i <= 100; i++) {
        if(v[i] >= n) {
            return v[i];
        }
    }
}
int main() {
    TG;
    H;
    long long n;
    while(cin >> n) {
        cout << Tribonacci(n) << '\n';
    }
    TGH;
}