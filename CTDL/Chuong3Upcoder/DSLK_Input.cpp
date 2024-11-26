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
    node *tmp = head;
    node *newNode = makeNode(x);
    while(tmp != nullptr) {
        if(tmp->data == x) {
            return;
        }
        tmp = tmp->next;
    } 
    if(head == nullptr) {
        head = newNode; return;
    } else {
        node *tmp = head;
    if(tmp == nullptr) {
        return;
    }
    while(tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    }
}
void duyet(node *head) {
    node *tmp = head;
    while(tmp != nullptr) {
        cout << tmp->data << ' ';
        tmp = tmp->next;
    }
}
int main () {
    node *head = nullptr;
    int m;
    while(cin >> m) {
        pushBack(head, m);
    }
    duyet(head);
}
