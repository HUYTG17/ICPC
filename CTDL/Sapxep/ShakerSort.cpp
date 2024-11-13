#include <iostream>

using namespace std;

void shakerSort(int a[], int n)
{
    int right, left, k, i;
    left = 0;
    right = n - 1;
    k = n - 1;
    while(left < right)
    {
        for(int i = right; i > left; i--)
            if(a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                k = i;
            }
        left = k;
        
        for(int i = left; i < right; i++)
            if(a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                k = i;
            }   
        right = k;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    shakerSort(a, n);
    for(int x : a) cout << x << ' ';
}