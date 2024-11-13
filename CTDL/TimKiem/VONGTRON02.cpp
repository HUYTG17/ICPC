#include <iostream>
#include <vector>

using namespace std;

void Vtrong(int a[], int n, int k) {
    vector<int> result;
    vector<int> people(n);
    int index = 0;
    for(int i = 0; i < n; i++) {
        people[i] = i;
    }
    int i = 0;
    while(people.size() > 0) {
        if(i == k) {
            i = 0;
        }
        index = (index + a[i] - 1) % people.size();
        result.push_back(people[index]);
        people.erase(people.begin() + index);
        i++;
    }
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    int a[k];
    for(int i = 0; i < k; i++) {
        cin >> a[i];
    }
    Vtrong(a, n, k);
}