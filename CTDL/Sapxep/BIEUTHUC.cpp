#include <bits/stdc++.h>
#define ll long long

using namespace std;

void quickSort(ll a[], ll left, ll right)
{
    if(left >= right) return;
    int x = a[(left + right) / 2];
    int i = left, j = right;
    while(i < j)
    {
        while(a[i] > x) i++;
        while(a[j] < x) j--;
        if(i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    quickSort(a, left, j);
    quickSort(a, i, right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for(ll i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    ll sum = a[0];
    a[0] = 0;
    //sort(a, a + n, greater<int>());
    quickSort(a, 0, n - 1);
    for(ll i = 0; i < n; ++i)
    {
        if(i < k) sum += a[i];
        else sum -= a[i];
    }
    cout << sum;
    return 0;
}

// interchang, bubble, insertion, selection qua cham, nen quicksort ms nhanh or heapsort 
// ham sort cung duoc sort(a, a + n, greater<int>());