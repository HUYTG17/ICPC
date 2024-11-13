#include <iostream>
#include <vector>
using namespace std;
void vtron(int n, int k) {
    vector<int> result;
    vector<int> people(n);
    int index = 0;
    for(int i = 0; i < n; i++) {
        people[i] = i + 1;
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
// 0 1 2 3 4 5 6 7 8   1 2     8       
// index = 6 % 9 = 6; index = 12 % 8 = 4 index = 10 % 7 = 3;
// index = 9 % 6 = 3 index = 9 % 5 = 4; index = 6 % 4 = 2
// index = 8 % 3 = 2 index = 6 % 2 = 0 index 
int main() {
    int n, k; cin >> n >> k;
    vtron(n, k);
}