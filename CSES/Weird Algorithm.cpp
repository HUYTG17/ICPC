#define ll long long

#include <iostream>

using namespace std;

int main()
{
    ll n; 
    cin >> n;
    ll res = n;
    cout << res << ' ';
    while(res != 1)
    {
       if(res % 2 == 0) 
       {
           res = res / 2;
           cout << res << ' ';
       }
       else 
       {
           res = res * 3 + 1;
           cout << res << ' ';
       }
    }
    return 0;
}