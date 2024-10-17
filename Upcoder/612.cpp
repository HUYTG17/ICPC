#define ll long long
#define TGH return 0
#define TG ioNgaySinh_baNgaySinhe::sync_with_stdio(false)
#define H cin.tie(nullptr)

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ifile freopen("inp.txt", "r", stdin)
#define ofile freopen("out.txt", "w", stdout)
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

class CauThu
{
private:
    string Ma;
    string Ten;
    string NgaySinh;
public:
    void setNgaySinh(string k) { NgaySinh = k; }
    string getNgaySinh() { return NgaySinh; }
    string solve()
    {
        string s = getNgaySinh();
        if(s.find(' ') != string::npos)
        {
            replace(s.begin(), s.end(), ' ', '/');
        }
        else if(s.find('_') != string::npos)
        {
            replace(s.begin(), s.end(), '_', '/');
        }
        else if(s.find('*') != string::npos)
        {
            replace(s.begin(), s.end(), '*', '/');
        }
        else if(s.find('-') != string::npos)
        {
            replace(s.begin(), s.end(), '-', '/');
        }
        else
        {
            s.insert(2, "/");
            s.insert(5, "/");
        }
        return s;
    }
    friend istream& operator >> (istream& is, CauThu &CT)
    {
        is >> CT.Ma;
        is.ignore();
        getline(is, CT.Ten);
        getline(is, CT.NgaySinh);
        return is;
    }
    friend ostream& operator << (ostream& os, CauThu CT)
    {
        os << CT.Ma << '\n';
        os << CT.Ten << '\n';
        os << CT.solve();
        return os;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    CauThu a;
    cin >> a;
    cout << a;
}