#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int gondolas = 0;
    int i = 0, j = n - 1;
    while(i <= j) {
        if(a[i] + a[j] <= x) {
            i++;
            j--;
        } 
        else {
            j--;
        }
        gondolas++;
    }
    cout << gondolas;
    return 0;
}

/*#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, x, a;
    cin >> n >> x;
    multiset<int> se;
    for(int i = 0; i < n; i++) {
        cin >> a;
        se.insert(a);
    }
    int gondolas = 0;
    while(!se.empty()) {
        auto first = *se.begin();
        auto last = *se.rbegin();
        if(first + last <= x) {
             se.erase(se.find(first));
             se.erase(se.find(last));
        } 
        else {
             se.erase(se.find(last));
        }
        gondolas++;
    }
    cout << gondolas;
    return 0;
}*/ // con sai 4 test