#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int>& a, int x) 
{
    for(int i = 0; i < a.size(); i++) // for(int i = 0; i < a.size();)
    { 
        if(a[i] == x) 
        {
            a.erase(a.begin() + i);
            i--;
        }
        /*else 
        {
            i++;
        }*/
    }
}


int main() 
{
    int n, x; 
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    solve(v, x);
    for(auto it : v)
        cout << it << ' ';

}

/*// cách 2 dùng khi được xếp bé đến lớn 
// VD: 5 3
//   1 2 3 3 4
#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int>& v, int x)
{
    int l = 0;
    int r = v.size() - 1;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(v[mid] == x) 
        {
            v.erase(v.begin() + mid);
            r--;
        }
        else if(v[mid] < x) 
        {
            l = mid + 1;
        }
        else 
        {
            r = mid - 1;
        }
    }
}

int main() {
    int n, x; 
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    solve(v, x);
    for(auto it : v)
        cout << it << ' ';

}*/