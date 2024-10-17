#define TGHuy return 0
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int numA = 1, numB = 0;
    for(int i = 0; i < n; i++) {
        int NA = numB;
        int NB = numA + numB;
        
        numA = NA;
        numB = NB;
    }
    cout << numA << " " << numB;
    TGHuy;
}