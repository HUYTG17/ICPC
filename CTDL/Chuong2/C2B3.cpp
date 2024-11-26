#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
vector<string> v;

void binarySearch(int a[], int left, int right, int x)
{
    while(left <= right)
    {
        int mid = (left + right) / 2;
        cnt++;
        if(left == right)
        {
            cnt--;
        }
        if(a[mid] == x) break;
        else if(a[mid] < x) left = mid + 1;
        else right = mid - 1;
        
        string res = "- Lần " + to_string(cnt) + " : x=" + to_string(x) 
        + " nằm trong đoạn [" + to_string(left) + ".." + to_string(right)
        + "] // mid =" + to_string(mid);
        v.push_back(res);
    }
    cout << "- Số lần chia đôi của mảng là : " << cnt << '\n';
    for(auto it : v)
    {
        cout << it << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    binarySearch(a, 0, n - 1, x);
    return 0;
}