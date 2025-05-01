#include <iostream>

using namespace std;

int main()
{
    int a, b, u, v, x, y;
    cin >> a >> b >> u >> v >> x >> y;
    int adult = (x - y) * (a + u);
    int child = y * (b + v);
    cout << "Tổng số tiền vé: " << adult + child << " nghìn đồng";
}
