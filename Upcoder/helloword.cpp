#include <iostream>
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
using namespace std;
int main() 
{
    int a, b; 
    cin >> a >> b;
    cout << a + b;
    cout << '\n';
    cerr << "Time elapsed: " << TIME << " s.";
    return 0;
}