// // Với s = "aacccd" thì countChar = ["a 2", "c 3", "d 1"]
#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    map<char, int> mp;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
    }
    int cnt = 0;
    for(pair<char, int> it : mp) {
        cout << it.first << " " << it.second;
        cnt++;
        if(cnt < mp.size()) {
            cout << ", ";
        }
    }
}
// Bài 7 Cho một dãy gồm các số nguyên, 
// hãy đơn ra số thỏa mãn là số lớn nhất 
// trong những số có tần số bé nhất.
// Ví dụ:Với arr = [2,2,4,4,7,7,7] thì largestElement(arr) = 4.
// Với arr = [1,3,4,5,5] thì largestElement(arr) = 4
#include <iostream>
#include <map>

using namespace std;

int main() {
    int a[100];
    map<int, int> mp;
    int x, n = 0;
    while(cin >> x) {
        a[n++] = x; 
    }
    for(int i = 0; i < n; i++) {
        mp[a[i]]++;
    }
    int Min = mp.size();
    for(auto it : mp) {
        Min = min(Min, it.second);
    }
    int Max = -99999;
    for(auto it : mp) {
        if(it.second == Min) {
            Max = max(Max, it.first);
        }
    }
    cout << Max;
}
