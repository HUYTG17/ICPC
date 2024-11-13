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
    node *temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void duyet(node *head) {
    node *temp = head;
    while(temp != nullptr) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}
void cong(node *head) {
    node *temp = head;
    while(temp != nullptr) {
        if(temp->data % 2 != 0) {
            temp->data++;    
        }
        temp = temp->next;
    }
}
void nguoc(node *&head) {
    node *temp = head;
    node *tmp = nullptr;
    if(head == nullptr) {
        return;
    }
    while(temp != nullptr) {
        node *buc = temp->next;
        temp->next = tmp;
        tmp = temp;
        temp = buc;
    }
    head = tmp;
    temp = head;
    while(temp != nullptr) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
}
int main () {
    node *head = nullptr;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;
        pushBack(head, m);
    }
    duyet(head);
    cong(head);
    duyet(head);
    nguoc(head);
}