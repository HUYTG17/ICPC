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
void pushFront(node *&head, int x) {
    node *newNode = makeNode(x);
    if(newNode == nullptr) {
        return;
    }
    newNode->next = head;
    head = newNode;
}
void duyet(node *head) {
    node *tmp = head;
    while(tmp != nullptr) {
        cout << tmp->data;
        if(tmp->next != nullptr) {
            cout << ' ';
        }
        tmp = tmp->next;
    }
}
int main () {
    node *head = nullptr;
    int m;
    while(cin >> m) {
        pushFront(head, m);
    }
    duyet(head);
}