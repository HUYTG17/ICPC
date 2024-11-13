#include <bits/stdc++.h>

using namespace std;

int DemSo0TanCungGiaiThua(int n)
{
    int ans;
    for(int i = 5; i <= n; i *= 5)
    {
        ans += n / i;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    cout << DemSo0TanCungGiaiThua(n);
    return 0;
}