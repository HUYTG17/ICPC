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
void printMiddle(node *&head) {
    if(head == nullptr || head->next == nullptr) {
        cout << "Empty";
        return;
    }
    node *slow = head;
    node *fast = head;
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    while(slow != nullptr) {
        cout << slow->data << ' ';
        slow = slow->next;
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
    printMiddle(head);
}