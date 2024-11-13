#define TGH return 0
#define TG ios_base::sync_with_stdio(false)
#define H cin.tie(nullptr)

#include <iostream>
#include <vector>

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

void BubbleSort(vector<int>& a, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = n - 1; j > i; j--) {
            if(a[j] > a[j - 1]) {
                swap(a[j], a[j - 1]);
            }
        }
    }
}

int main() {
    TG; H;
    int n; cin >> n;
    vector<int> v1(n);
    vector<int> v2;
    for(int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for(int i = 0; i < n; i++) {
        if(IsPrime(v1[i])) {
            v2.push_back(v1[i]);
        }
    }
    BubbleSort(v2, v2.size());
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(IsPrime(v1[i])) {
            v1[i] = v2[index];
            index++;
        }
    }
    for(const auto p : v1) {
        cout << p << " ";
    }
    TGH;
}