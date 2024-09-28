#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int rounds = 1; 
    long long current_max = LLONG_MIN;  
    for (int i = 0; i < n; i++) {
        if (arr[i] < current_max) {
            rounds++; 
        }
         current_max = arr[i];
    }
    
    cout << rounds << endl;
    return 0;
}
