#define ll long long
#define TG ios::sync_with_stdio(false)
#define H cin.tie(0)

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ll n; 
    cin >> n;
    vector<ll> a, b;
    ll sum = 0;
    for(ll i = 0; i < n; i++)
    {
        sum += i + 1;
    }
    if(sum % 2 != 0) 
    {
        cout << "NO\n"; 
        return 0;
    }
    cout << "YES\n";
    ll sumDivide = sum / 2;
    for(int i = n; i > 0; i--)
    {
        if(sumDivide >= i)
        {
            a.push_back(i);
            sumDivide -= i;
        }
        else
        {
            b.push_back(i);
        }
    }
    cout << a.size() << '\n';
    for(auto it : a) cout << it << ' ';
    cout << '\n';
    cout << b.size() << '\n';
    for(auto it : b) cout << it << ' ';
    return 0;
}