#include <iostream>

using namespace std;

void Swap(int& a, int& b) {
    int r = a;
    a = b;
    b = r;
    cout << a << " " << b;
}
int main() {
    int a, b; cin >>  a >> b;
    Swap(a, b);
}