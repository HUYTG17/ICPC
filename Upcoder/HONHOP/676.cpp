#define ll long long
#define TGH return 0
#define fastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
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
const int maxN = 2e9 + 7;
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

class HS
{
private:
    string Ten;
    int DiemToan;
    int DiemVan;
    float Dtb;
public:
    HS(string _Ten = "", int _DiemToan = 0, int _DiemVan = 0, float _Dtb = 0.0)
    {
        Ten = _Ten;
        DiemToan = _DiemToan;
        DiemVan = _DiemVan;
        Dtb = _Dtb;
    }
    HS(const HS &hs)
    {
        Ten = hs.Ten;
        DiemToan = hs.DiemToan;
        DiemVan = hs.DiemVan;
        Dtb = hs.Dtb;
    }
    ~HS(){}
    void setDiemToan(int k) { DiemToan = k; }
    void setDiemVan(int k) { DiemVan = k; }
    int getDiemToan() { return DiemToan; }
    int getDiemVan() { return DiemVan; }
    friend istream& operator >> (istream& is, HS& hs)
    {
        is.ignore();
        getline(is, hs.Ten);
        is >> hs.DiemToan;
        is >> hs.DiemVan;
        is >> hs.Dtb;
        //is.ignore();
        return is;
    }
    friend ostream& operator << (ostream& os, HS hs)
    {
        os << hs.Ten << "-Toan: " << hs.DiemToan << "-Van: " << hs.DiemVan << "-DiemTB: "; 
        os << fixed << setprecision(1) << hs.Dtb;
        return os;
    }
};

int HSG(HS a[], int n)
{
    int dem = 0;
    for(int i = 0; i < n; ++i)
    {
        if(a[i].getDiemToan() >= 8 && a[i].getDiemVan() >= 8)
            {
                dem++;
            }
                
        }
    return dem;
}
    
int main() {
    fastIO;
    int n;
    cin >> n;
    HS a[10];
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        cout << a[i] << '\n';
    }
    cout << "So luong HSG: " << HSG(a, n);
    TGH;
}