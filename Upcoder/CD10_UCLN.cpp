#include <iostream>

using namespace std;

int UCLN(int a, int b)
{
    if(b == 0) return a;
    return UCLN(b, a % b);
} // nhanh hơn rất nhiều vì hia lấy dư
/*
int UCLN1(int a, int b)
{
    if(a == b) return a;
    if(a > b) 
        return UCLN1(a - b, b);
    return UCLN1(a, b - a);
}
*/
int main()
{
    int a, b;
    cin >> a >> b;
    cout << UCLN1(a, b);
}
