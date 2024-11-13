#include <iostream>
using namespace std;
void linearsearch(int a[], int n, int x) {
    int firstpos = -1, lastpos = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] == x) {
            lastpos = i;
        } 
        if(a[i] > x && firstpos == -1) {
            firstpos = i; // break k đc full diem;
        }
    }
    if(lastpos != -1) {
        cout << "Y\n" << lastpos;
    } else {
        if(firstpos != -1) {
            cout << "N\n" << firstpos;
        } else {
            cout << "N\n" << -1;
        }
    }
}
// th x = 7 và phan tu có 7 8 7 thi last luu đc 2 va tim đc cái cuối
// 1 if 1 else if thì nếu 1 = 1 > nó xen kẽ k tìm dc9 cái cúi 
// 2 if thì luu  d nhieu i vi tri va la vi tri cui cung
int main() {
    int n, x, a[100]; cin >> n >> x;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    linearsearch(a, n, x);
}
