#include <iostream>
#include <vector>

using namespace std;

vector<int> solve(vector<int>& v, int x)
{
    vector<int> a;
    for(int i = 0; i < v.size(); i++) 
    {
        if(v[i] == x)
        {
            a.push_back(i);
        }
    }
    return a;
}

int main() 
{   
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> v1 = solve(v, x);
    for(auto it : v1)
        cout << it << ' ';
    return 0;
}
/*// cách 2 xài mảng 
#include <iostream>
#include <vector>

using namespace std;

vector<int> solve(int a[], int n, int x)
{
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == x)
        {
            v.push_back(i);
        }
    }
    return v;
}

int main()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> v = solve(a, n, x);
    for(auto it : v)
        cout << it << ' ';
    return 0;
}*/

/*
#include <iostream>

using namespace std;

int main() 
{
    int n, q;
    cin >> n >> q;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] == q)
        {
            cout << i << ' ';
        }
    }
}
*/