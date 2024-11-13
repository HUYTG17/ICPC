#include <iostream>

using namespace std;

void BubbleSort(char *a, int n, char c) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = n - 1; j > i; j--) {
            if(c == 'A') {
                if(tolower(a[j]) < tolower(a[j - 1]))
                   swap(a[j], a[j - 1]);
                else if((tolower(a[j]) == tolower(a[j - 1])) && (a[j] > a[j - 1]))
                   swap(a[j], a[j - 1]);
            }
            else {
                if(tolower(a[j]) > tolower(a[j - 1]))
                   swap(a[j],a[j -1]);
                else if((tolower(a[j]) == tolower(a[j - 1])) && (a[j] < a[j - 1]))
                   swap(a[j], a[j - 1]);
            }
        }
    }
}

void Input(char *a, int n) {
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void Output(char *a, int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char c; int n; char *a = new char[n];
    cin >> c >> n;
    Input(a, n);
    BubbleSort(a, n, c);
    Output(a, n);
    return 0;
}