#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) v.push_back(i);
    int xoay;
    vector<int>::iterator it = v.begin();
    while (cin >> xoay) {
        int k = abs (xoay);
        if (xoay < 0) {
            while (k--) {
                if (it == v.begin())
                    it = v.end();
                --it;
            }
        } else {
            while (k--) {
                ++it;
                if (it == v.end()) it = v.begin();
            }
        }
        cout << *it << ' ';
    }

    return 0;
}