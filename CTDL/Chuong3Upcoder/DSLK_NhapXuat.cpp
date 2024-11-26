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
void duyet(node *head) {
    node *tmp = head;
    while(tmp != nullptr) {
        cout << tmp->data << ' ';
        tmp = tmp->next;
    }
}
int main () {
    node *head = nullptr;
    int data;
    do {
        cin >> data;
        if(data == -1) {
            break;
        }
        pushBack(head, data);
    } while(data != -1);
    cout << "DSLK ban dau: ";
    duyet(head);
}