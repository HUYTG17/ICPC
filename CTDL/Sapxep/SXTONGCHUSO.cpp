#include <iostream>

using namespace std;

bool IsPrime(int n) {
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int sumofDigits(int n) {
    int sum = 0;
    while(n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void interchangeSort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(sumofDigits(a[i]) < sumofDigits(a[j])) {
                swap(a[i], a[j]);
            } 
            else if(sumofDigits(a[i]) == sumofDigits(a[j])) {
                string str1 = to_string(a[i]);
                string str2 = to_string(a[j]);
                if(str1.size() > str2.size()) {
                    swap(a[i], a[j]);
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int x : a) {
        int sum = sumofDigits(x);
        if(IsPrime(sum)) {
            cout << x << ' ';
        }
    }
    cout << '\n';
    interchangeSort(a, n);
    for(int x : a) {
        cout << x << ' ';
    }
    return 0;
}