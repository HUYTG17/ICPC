#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool sdx(int n)
{
    int res = n, sum = 0;
    while(n)
    {
        sum = sum * 10 + n % 10;
        n /= 10;
    }
    return (res == sum);
}

int main()
{
    ifstream in("vector_inp.txt");
    ofstream out("vector_out.txt");
    int n;
    vector<int> v, v2;
    while(in >> n)
    {
        if(sdx(n)) v.push_back(n);
        else v2.push_back(n);
    }
    int Max = -1e5 + 7;
    int s = 0;
    for(auto it : v)
    {
        Max = max(Max, it);
        s += it;
    }
    out << Max << ' ' << s << '\n';
    sort(v.begin(), v.end(), greater<int>());
    for(auto it : v) out << it << ' ';
    out << '\n';
    int Min = 1e5 + 7;
    int s2 = 0;
    for(auto it : v2)
    {
        Min = min(Min, it);
        s2 += it;
    }
    out << Min << ' ' << s2 << '\n';
    sort(v2.begin(), v2.end());
    for(auto it : v2) out << it << ' ';
    out.close();
    in.close();
}