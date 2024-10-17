#include <iostream>
#include <map>

using namespace std;

int main(){
    map<int, int> mp;
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        mp[a[i]]++;
    }
    // for(auto p : mp) {
    //     cout << p.first << " " << p.second << endl;
    // }
    // for(auto it = mp.rbegin(); it != mp.rend(); it++) {
    //     cout << (*it).first << " " << (*it).second << endl; ot it->first
    // }
    // auto it1 = mp.begin();
    // cout << (*it1).first << " " << (*it1).second << endl;
    // auto it2 = mp.rbegin();
    // cout << (*it2).first << " " << (*it2).second;
    // map<int, int> :: iterator it1 = mp.begin();
    // cout << (*it1).first << " " << (*it1).second;
    
    return 0;
    
}

#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main() {
    int n; cin >> n;
    int a[n];
    // map or multimap<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp.insert({a[i], 1});
    }
    for(auto p : mp) {
        cout << p.first << " ";
    }
}