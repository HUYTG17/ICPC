#include <iostream>
#include <cmath>

using namespace std;

struct Node {
    int value;
    Node* next; //luon luon co
};
struct List {
    Node* pFirst;
    Node* pLast;
};
void initList(List& l) {
    l.pFirst = l.pLast = NULL;
}
Node* getNode(int c) {
    Node* p = new Node;
    p->value = c;
    p->next = NULL;
    return p;
}
void addNode(List& l, Node* p) {
    if (l.pFirst == NULL) {
        l.pFirst = l.pLast = p;
    }
    else {
        l.pLast->next = p;
        l.pLast = p;
    }
}
void addHead(List& l, Node* p) {
    if (l.pFirst == NULL) {
        l.pFirst = l.pLast = p;
    }
    else {
        p->next = l.pFirst;
        l.pFirst = p;
    }
}

void printList(List l) {
    Node* pt = l.pFirst;
    while (pt != l.pLast) {
        cout << (pt->value) << " ";
        pt = pt->next;
    }
    cout << l.pLast->value;
    cout << endl;
}

int main() {
    List l;
    initList(l);
    int n, k;
    cin >> n >> k;
    if (k > 0){
        for (int i = 0; i < n; i++) {
            addNode(l, getNode(i));
        }
    }else{
        addNode(l, getNode(0));
        for (int i = 1; i < n; i++) {
            addNode(l, getNode(n - i));
        }
    }
    
    //printList(l);

    //xu ly
    int dem = 0, count = 0;
    l.pLast->next = l.pFirst;
    
    Node* curr = l.pFirst;
    Node* currLast = l.pLast;
    while (n > 0) {
        dem++;
        if (dem == abs(k)) {
            dem = 0;
            n--;
            Node* p = curr;
            currLast->next = curr->next;
            cout << curr->value << " ";
            delete p;
            curr = curr->next;
            continue;
        }
        currLast = curr;
        curr = curr->next;
    }
    return 0;
}
