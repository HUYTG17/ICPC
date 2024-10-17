#define TrGiaHuy return 0
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<vector<string>> v(n, vector<string>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
         cin >> v[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == "abcde") {
                char c = j + 'A';
                cout << c << i + 1;
            }
        }
    }
    TrGiaHuy;
}