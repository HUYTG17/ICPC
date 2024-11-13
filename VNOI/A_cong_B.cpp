#include <iostream>

using namespace std;

int add(int a, int b)
{
    while(b != 0)
    {
        int carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << add(a, b);
    return 0;
}