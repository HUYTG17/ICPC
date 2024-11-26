#include <iostream>
using namespace std;
struct node {
    char data;
    node *next;
};
node *makeNode(char x) {
    node *newNode = new node;
    if(newNode == nullptr) {
        return nullptr;
    }
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}
void pushBack(node *&head, char x) {
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
void tang(node *head) {
    node *tmp = head;
    while(tmp != nullptr && tmp->next != nullptr) {
        if(tmp->data > tmp->next->data) {
            tmp->next = tmp->next->next;
        }
        else {
            tmp = tmp->next;
        }
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
    char c;
    while(cin >> c) {
        pushBack(head, c);
    }
    tang(head);
    duyet(head);
}