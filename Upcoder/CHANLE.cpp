#define TGH return 0
#define TG ios_base::sync_with_stdio(false)
#define H cin.tie(nullptr)

#include <iostream>

using namespace std;

int main() {
    TG; H;
    int n; cin >> n;
    if(n % 2 == 0) {
        cout << "chan";
    } else {
        cout << "le";
    }
    TGH;
}