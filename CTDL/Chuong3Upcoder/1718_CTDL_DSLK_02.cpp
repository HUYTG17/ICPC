#include <iostream>
#include <cmath>
using namespace std;
struct node {
    int data;
    node *next;
};
node *makeNode(int x) {
    node *newNode = new node;
    if(newNode == nullptr) {
        return nullptr;
    }
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}
bool snt(int n) {
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}
bool scp(int n) {
    int kq = sqrt(n);
    return kq*kq == n;
}
bool shc(int n) {
    int s = 0;
    for(int i = 1; i < n; i++) {
        if(n % i == 0) {
            s += i;
        }
    }
    return s == n;
}
void pushBack(node *&head, int x) {
    node *newNode = makeNode(x);
    if(newNode == nullptr) {
        return;
    }
    if(head == nullptr) {
        head = newNode; return;
    }
    node *tmp = head;
    while(tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}
void duyet(node *head) {
    node *tmp = head;
    while(tmp != nullptr) {
        cout << tmp->data;
        if(tmp->next != nullptr) cout << ' ';
        tmp = tmp->next;
    }
}
int main () {
    node *nt = nullptr;
    node *cp = nullptr;
    node *hc = nullptr;
    int n;
    int a = 0, b = 0, c = 0;
    while(cin >> n) {
        if(snt(n)) {
            pushBack(nt, n); a++;
        }
        else if(scp(n)) {
            pushBack(cp, n); b++;
        }
        else if(shc(n)) {
            pushBack(hc, n); c++;
        }
    }
    if(a == 0) cout << "NULL";
    else duyet(nt);
    cout << endl;
    if(b == 0) cout << "NULL";
    else duyet(cp);
    cout << endl;
    if(c == 0) cout << "NULL";
    else duyet(hc);
}