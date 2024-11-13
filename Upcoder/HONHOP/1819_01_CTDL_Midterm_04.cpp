#include <bits/stdc++.h>

using namespace std;

void quickSortUp(vector<int> &a, int left, int right)
{
    if(left >= right) return;
    int pivot = a[(left + right) / 2];
    int i = left, j = right;
    while(i < j)
    {
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;
        if(i <= j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++; 
            j--;
        }
    }
    quickSortUp(a, left, j);
    quickSortUp(a, i, right);
}

void quickSortDown(vector<int> &a, int left, int right)
{
    if(left >= right) return;
    int pivot = a[(left + right) / 2];
    int i = left, j = right;
    while(i < j)
    {
        while(a[i] > pivot) i++;
        while(a[j] < pivot) j--;
        if(i <= j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++; 
            j--;
        }
    }
    quickSortDown(a, left, j);
    quickSortDown(a, i, right);
}
int main()
{
    int x;
    vector<int> v;
    while(cin >> x)
    {
        v.push_back(x);
        if(cin.peek() == '\n') break;
    }
    int mid = v.size() / 2;
    sort(v.begin(), v.begin() + mid);
    sort(v.begin() + mid, v.end(), greater<int>());
    //quickSortUp(v, 0, mid - 1);
    //quickSortDown(v, mid, v.size() - 1);
    for(auto it : v)
    {
        cout << it << ' ';
    }
}