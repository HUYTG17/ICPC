#define ll long long
#define TGH return 0
#define TG ios_base::sync_with_stdio(false)
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

int main() {
    TG; H;
    double A1, A2;
    ifile;
    ofile;
    //A1 = m(O2), A2 = m(H2O)

    //Hỗn hợp B
    double B;
    //B = m(H2O)

    //Hỗn hợp E
    double E1, E2;
    //E1 = m tăng, E2 = m(H2O)

    //Tỉ lệ
    //T1 = O, T2 = O2
    int T1, T2;
    cin >> A1 >> A2;
    cin >> B;
    cin >> E1 >> E2;
    cin >> T1 >> T2;
    if (T1 < T2) swap(T1, T2);
    //Xử lý hỗn hợp E
    double molH2OE = E2/18.0;
    double molE = (molH2OE)/4;
    double molC3H8O = molE*T1/(T1 + T2);
    double molC3H8O2 = molE - molC3H8O;
    //cout << molC3H8O2 << '\n' << molC3H8O;

    //Xử lý hỗn hợp A
    double molO2A = A1/32.0;
    double molX = molC3H8O, molY = molC3H8O2;
    double molZ = (molO2A*4 - molX*34.0 - molY*36.0)/(44.0);
    double mA = 170.0*molX + 180.0*molY + 204.0*molZ;
    cout << fixed << setprecision(2) << (204.0*molZ)*100.0/mA;
    cout << '%';
    TGH;
}