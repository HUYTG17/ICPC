// #include <bits/stdc++.h>
// #define lli long long int

// using namespace std;

// lli solve(lli n) {
//     return (n * (n + 1) * (2 * n + 1)) / 6;
// }

// int main() {
//     lli a, b, m;
//     cin >> a >> b >> m;

//     lli res = (solve(b) - solve(a - 1)) % m;

//     if (res < 0) {
//         res += m;
//     }
//     cout << res << endl;
//     return 0;
// }

#include<bits/stdc++.h>
#define lli long long int
using namespace std;

// int main()
// {
//     lli A, B, M, sum;
//     cin>>A>>B>>M;
//     if(A <= 0) return 0;
//     lli res_1 = ((B%M)*(B%M+1%M)*(B%M+2%M));
//     lli res_2 = ((A%M-1%M)*(A%M)*(A%M+1%M));
//     lli res_3 = (B%M+A%M);
//     lli res_4 = (B%M-A%M+1%M);
//     sum = (res_1 - res_2)/3 - (res_3*res_4)/2;
//     cout<<sum;
// }

#include <iostream>
#define lli long long int

using namespace std;

lli solve(lli n, lli M) {
    return (n%M * (n%M + 1%M) * (2%M * n%M + 1%M)) / 6;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli A, B, M;
    cin >> A >> B >> M;
    lli sum_b = solve(B, M);
    lli sum_a = solve(A - 1, M);
    lli S = sum_b - sum_a;
    lli result = S % M;
    if (result < 0) {
        result += M;
    }
    cout << result << endl;
    return 0;
}