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
        tmp = tmp->next;
    }
    cout << endl;
}
void alpha(node *head) {
    node *tmp = head;
    char c = 'A';
    while(tmp != nullptr) {
        while(c <= tmp->data) {
            cout << c;
            c++;
        }
        tmp = tmp->next;
    }
    while(c <= 'Z') {
        cout << c;
        c++;
    }
}
int main () {
    node *head = nullptr;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        pushBack(head, c);
    }
    duyet(head);
    alpha(head);
}