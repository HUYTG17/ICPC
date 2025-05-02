#include <bits/stdc++.h>

using namespace std;

int main()
{
    float canh1, canh2;
    cin >> canh1 >> canh2;
    float Stgvuong = (canh1 * canh2) / 2;
    float ch = sqrt(pow(canh1, 2) + pow(canh2, 2));
    cout << fixed << setprecision(1);
    cout << Stgvuong << '\n';
    cout << ch;
}
