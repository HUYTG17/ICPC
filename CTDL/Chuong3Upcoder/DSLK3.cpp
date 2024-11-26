#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
};
typedef Node *node;
node makeNode(int x) {
    node newNode = new Node;
    if(newNode == nullptr) {
        return nullptr;
    }
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}
void duyet(node &head) {
    node temp = head;
    int cnt = 0;
    while(temp != nullptr) {
        cnt++;
        temp = temp->next;
    }
    cout << cnt << endl;
    node temp1 = head;

    if(temp1 == nullptr || temp1->next == nullptr) {
        cout << "NO" << endl;
    }
    else {
        node temp1 = head->next;
    while(temp1 != nullptr) {
        cout << temp1->data << ' ';
        temp1 = temp1->next;
        }
        cout << endl;
    }
}
void demchan(node &head) {
    node temp = head->next;
    int cnt = 0;
    while(temp != nullptr) {
        if(temp->data % 2 == 0) {
            cnt++;
        }
        temp = temp->next;
    }
    if(cnt == 0) {
        cout << "NO" << endl;
    }
    else {
        cout << cnt;
    }
}
void pushBack(node &head, int x) {
    node newNode = makeNode(x);
    if(head == nullptr) {
        head = newNode; return;
    }
    node temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}
int main () {
    node head = nullptr;
    int n;
    while(cin >> n) {
        pushBack(head, n);
    }
    duyet(head);
    demchan(head);
}