#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    cout << "Tổng ba số: ";
    cout << a + b + c << '\n';
    cout << "Tổng bình phương ba số: " ;
    long long ans = pow(a, 2) + pow(b, 2) + pow(c, 2); // pow tra ve double la 1e+... nen phai dung bien tam long long ans
    cout << ans; 
}
