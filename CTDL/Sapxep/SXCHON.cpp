#include <bits/stdc++.h>

using namespace std;

void InsertionSort(int a[], int n)
{
    int x, pos;
    for(int i = 1; i < n; i++)
    {
        x = a[i];
        for(pos = i; (pos > 0) && (a[pos - 1] > x); pos--)
            a[pos] = a[pos - 1];
        a[pos] = x;
    }
}

int main()
{
    int x;
    int a[100];
    int n = 0;
    while(cin >> x)
    {
        a[n++] = x;
    }
    InsertionSort(a, n);
    for(int i = 0; i < n; i++) 
    {
        cout << a[i] << ' ';
    } // int i : a chi dung khi co so luong phan tu tinh va duoc xac dinh roi
    return 0;
}