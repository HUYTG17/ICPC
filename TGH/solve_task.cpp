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
    string solve()
    {
        string s1 = NgaySinh.substr(0, NgaySinh.find(' '));
        int pos = NgaySinh.find(' ');
        s1.erase(pos);
        s1 += '/';
        s1 += NgaySinh.substr(pos + 1, NgaySinh.find(' '));
        pos = pos + NgaySinh.find(' ');
        s1.erase(pos + 1);
        s1 += '/';
        pos = pos + NgaySinh.find(' ');
        s1.erase(pos);
        s1 += NgaySinh.substr(pos + 1);
        return s1;
    }
    friend iostream& is >> (istream& is, CauThu &CT)
    {
        is >> CT.Ma;
        is.ignore();
        getline(is, CT.Ten);
        getline(is, CT.NgaySinh);
        return is;
    }
    friend ostream& os << (ostream& os, CauThu CT)
    {
        os << CT.Ma << '\n';
        os << CT.Ten << '\n';
        os << solve();
        return os;
    }
};

int main() {
    TG; H;
    ifile;
    ofile;
    TGH;
}