/*
viết chương trình tạo 2 danh sách số nguyên L1 và L2. 
Sau đó, tạo danh sách L3 chứa dãy con (bao gồm các số liên tiếp nhau trong mảng) 
đầu tiên của danh sách L1 mà dãy con này có trong danh sách L2 
ví dụ input: 
danh sách L1: 2 6 1 5 4 3 8 7 9 
danh sách L2: 8 3 6 1 5 4 3 7 9 0 
output: danh sách 
L3: 6 5 1 4 3*/

#include <bits/stdc++.h>

using namespace std;

class LinkedList;
class Node
{
    friend class LinkedList;
private:
    int _data;
    Node* _pNext;
public:
    Node(int data) : _data(data), _pNext(nullptr) {}
    void display();
};

void Node::display()
{
    cout << _data << ' ';
}

class LinkedList
{
private:
    Node* _pHead;
    Node* _pTail;
    int _iSize;
public:
    LinkedList() : _pHead(nullptr), _pTail(nullptr), _iSize(0) {}
    void addTail(int data);
    
    void findFirstSubsequence(LinkedList& lt1, LinkedList& lt2);
    void display();
};

void LinkedList::addTail(int data)
{
    Node* pAdd = new Node(data);
    if(_pHead == nullptr)
    {
        _pHead = _pTail = pAdd;
    }
    else
    {
        _pTail->_pNext = pAdd;
        _pTail = pAdd;
    }
    _iSize++;
}

void LinkedList::display()
{
    Node* pTemp = _pHead;
    while(pTemp != nullptr)
    {
        pTemp->display();
        pTemp = pTemp->_pNext;
    }
    cout << '\n';
}

void LinkedList::findFirstSubsequence(LinkedList& lt1, LinkedList& lt2)
{
    Node* p1 = lt1._pHead;
    while(p1 != nullptr)
    {
        Node* p2 = lt2._pHead;
        Node* start = p1;
        while(p2 != nullptr)
        {
            Node* pTemp1 = start;
            Node* pTemp2 = p2;
            while(pTemp1 != nullptr && pTemp2 != nullptr && pTemp1->_data == pTemp2->_data)
            {
                this->addTail(pTemp1->_data);
                pTemp1 = pTemp1->_pNext;
                pTemp2 = pTemp2->_pNext;
            }
            if(this->_pHead != nullptr) return;
            p2 = p2->_pNext;
        }
        p1 = p1->_pNext;
    }
}

int main()
{
    LinkedList L1, L2, L3;
    int val;
    while(cin >> val)
    {
        L1.addTail(val);
        if(cin.peek() == '\n')
            break;
    }
    int val1;
    while(cin >> val1)
    {
        L2.addTail(val1);
        if(cin.peek() == '\n')
            break;
    }
    cout << "Danh sach L1: ";
    L1.display();
    cout << "Danh sach L2: ";
    L2.display();
    L3.findFirstSubsequence(L1, L2);
    cout << "Danh sach L3: ";
    L3.display();
}
