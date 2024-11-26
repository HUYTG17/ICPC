#include <iostream>
using namespace std;
bool isPrime(int n) {
    if(n < 2) return false;
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}
void duyet(int *a, int b, int c) {
    for(int i = b;  i <= c; i++) {
        if(isPrime(i)) {
            cout << i << " ";
        }
    }
}
int main () {
    int b, c;
    cin >> b >> c;
    int *a = new int [100];
    // for(int i = b; i <= c; i++) {
        duyet(a, b, c);
    
}