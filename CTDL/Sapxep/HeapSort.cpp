#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

using namespace std;

void shift(int a[], int left, int right)
{
    int curr = left;
    int joint = 2 * curr + 1;
    int x  = a[curr];
    while(joint <= right)
    {
        if(joint < right)
            if(a[joint] < a[joint + 1]) // doi la giam
                joint = joint + 1;
        if(a[joint] < x) break; // doi la giam
        a[curr] = a[joint];
        curr = joint;
        joint = 2 * curr + 1;
    }
    a[curr] = x;
}
/*
3 2 5 1 6 8 4 7
8 7 5 2 6 3 4 1
B1:
r = 7
1 7 5 2 6 3 4 8
r = 6
7 6 5 2 1 3 4 8
B2:
4 6 5 2 1 3 7 8
r = 5
6 4 5 2 1 3 7 8
B3
3 4 5 2 1 6 7 8
r = 4
5 4 3 2 1 6 7 8
B4:
1 4 3 2 5 6 7 8
r = 3
4 2 3 1 5 6 7 8
B5:
1 2 3 4 5 6 7 8
r = 2
3 2 1 4 5 6 7 8
B6:
 1 2 3 4 5 6 7 8
 r = 1
 2 1 3 4 5 6 7 8
 B7:
 1 2 3 4 5 6 7 8
 r = 0
*/

















/*
3 2 5 1 6 8 4 7
left = 3 2 1 0
8 7 5 2 6 3 4 1

B1: 
1 7 5 2 6 3 4 8
r = 6
7 6 5 2 1 3 4 8
B2:
4 6 5 2 1 3 7 8
r = 5
6 4 5 2 1 3 7 8
B3:
3 4 5 2 1 6 7 8
r = 4
5 4 3 2 1 6 7 8
B4:
1 4 3 2 5 6 7 8
r = 3
4 2 3 1 5 6 7 8
B5:
1 2 3 4 5 6 7 8
r = 2
3 2 1 4 5 6 7 8
B6:
1 2 3 4 5 6 7 8
r = 1
2 1 3 4 5 6 7 8
B7
1 2 3 4 5 6 7 8
r = 0
*/

void createHeap(int a[], int n)
{
    for(int left = (n - 1) / 2; left >= 0; left--)
        shift(a, left, n - 1);
}

void Heapsort(int a[], int n)
{
    createHeap(a, n);
    int right = n - 1;
    while(right > 0)
    {
        swap(a[0], a[right]);
        right--;
        shift(a, 0, right);
    }
}

int main()
{
    fastIO;
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    Heapsort(a, n);
    for(int i = 0; i < n; ++i)
    {
        cout << a[i] << ' ';
    }
    return 0;
}