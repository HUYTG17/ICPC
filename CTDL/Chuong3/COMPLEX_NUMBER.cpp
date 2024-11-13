#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
struct SP {
    double thuc, ao;
    friend istream& operator >> (istream& is, SP &sp) {
    is >> sp.thuc >> sp.ao;
    return is;
    }
    friend ostream& operator << (ostream& os, SP sp) {
        os << "{";
        if(sp.ao == 0) os << sp.thuc;
        else if(sp.thuc == 0) {
            if(sp.ao > 0) os << "+" << sp.ao;
            else if(sp.ao < 0) os << sp.ao;
        }
        else if(sp.ao > 0) os << sp.thuc << "+" << sp.ao;
        else if(sp.ao < 0) os << sp.thuc << sp.ao;
        os << "i}" << " ";
     return os;
    }
    SP operator + (SP a) {
        SP tong;
        tong.thuc = this->thuc + a.thuc;
        tong.ao =this->ao + a.ao;
        return tong;
    }
    SP operator - (SP a) {
        SP tong;
        tong.thuc = this->thuc - a.thuc;
        tong.ao = this->ao + a.ao;
    }
    double modun() {
        double kq = sqrt(pow (this->thuc, 2) + pow(this->ao, 2));
        return kq;
    }
};
// void dun(int *a, int n) {
//     for(int i = 0; i < n; i++) {
//         cout << fixed << setprecision(2) << a[i].modun() << " ";
//     }
// }
// void cong(int *a, int n) {
//     SP s = a[0];
//     for(int i = 0; i < n; i++) {
//         s = s + a[i];
//     }
//     cout << s;
// }
int main () {
    SP *a = new SP [100];
    SP b;
    int n = 0;
    while(cin >> b) {
        a[n++] = b;
    }
    for(int i = 0; i < n; i++) {
        cout << a[i];
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        cout << fixed << setprecision(2) << a[i].modun() << " ";
    }
    cout << endl;
    SP s = a[0];
    for(int i = 1; i < n; i++) {
        s = s + a[i];
    }
    cout << fixed << setprecision(0) << s;
}