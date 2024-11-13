#include <iostream>
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
void duyet(node *head, int k) {
    node *tmp = head;
    int cnt = 0;
    while(tmp != nullptr) {
        cnt++;
        if(cnt > k) cout << tmp->data << ' ';
        tmp = tmp->next;
    }
    int dem = 0;
    while(head != nullptr) {
        dem++;
        if(dem <= k) cout << head->data << ' ';
        else break;
        head = head->next;
    }
}
int main () {
    node *head = nullptr;
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;
        pushBack(head, m);
    }
    duyet(head, k);
}