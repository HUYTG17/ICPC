#include <iostream>
#include <vector>
using namespace std;
void vtron(int n, int k) {
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
    for(const auto& p : result) {
        cout << p << " ";
    }
}
int main() {
    int n, k; cin >> n >> k;
    vtron(n, k);
}