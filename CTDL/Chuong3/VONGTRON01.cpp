#include <iostream>
#include <vector>
using namespace std;
void Vtron(int n, int k) {
    vector<int> result;
    vector<int> people(n);
    int index = 0;
    for(int i = 0; i < n; i++) {
        people[i] = i;
    }
    while(people.size() > 0) {
        index = (index + k - 1) % people.size();
        result.push_back(people[index]);
        people.erase(people.begin() + index);
    }
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    Vtron(n, m);
}