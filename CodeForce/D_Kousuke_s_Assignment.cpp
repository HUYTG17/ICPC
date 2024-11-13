#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int m;
    cin >> m;
    while (m--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        unordered_map<int, int> Smap;
        int curr = 0, cnt = 0, last = -1;
        for (int i = 0; i < n; ++i) {
            curr += a[i];
            if (curr == 0) {
                cnt++;
                last = i;
                curr = 0;
                Smap.clear();
            } else {
                if (Smap.count(curr)) {
                    if (Smap[curr] >= last) {
                        cnt++;
                        last = i;
                        curr = 0;
                        Smap.clear();
                    }
                }
            }
            Smap[curr] = i;
        }
        cout << cnt << endl;
    }
    return 0;
}
