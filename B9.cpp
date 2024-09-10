// Bài 9 : Bạn có một danh sách các giao dịch ngân hàng với số tiền và loại giao dịch (nạp, rút). Hãy tính số dư cuối cùng của tài khoản và tìm giao dịch lớn nhất theo từng loại.
// Ví dụ :
// Input :
// 7
// nap 500
// rut 200
// nap 300
// rut 100
// nap 400
// rut 300
// nap 100
// Output :
// So du cuoi cung: 700
// Giao dich nap lon nhat: 500
// Giao dich rut lon nhat: 300
#include <iostream>
#include <map>

using namespace std;

int main() {
    int n; cin >> n;
    map<string, int> mp;
    mp["nap"] = 0;
    mp["rut"] = 0;
    int sodu = 0;
    for(int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        if(s == "nap") {
            sodu += x;
            mp["nap"] = max(mp["nap"], x);
        } else if(s == "rut") {
            sodu -= x;
            mp["rut"] = max(mp["rut"], x);
        }
    }
    cout << "So du cuoi cung: " << sodu << "\n";
    cout << "Giao dich nap lon nhat: " << mp["nap"] << "\n";
    cout << "Giao dich rut lon nhat: " << mp["rut"];
}