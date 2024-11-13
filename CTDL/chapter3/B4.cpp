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
    
    bool contains(int data); 
    void Hieu(LinkedList& lt1, LinkedList& lt2);
    void Giao(LinkedList& lt1, LinkedList& lt2);
    void Hop(LinkedList& lt1, LinkedList& lt2);
    void InterchangeSort();
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

bool LinkedList::contains(int data)
{
    Node* pTemp = _pHead;
    while(pTemp != nullptr)
    {
        if(pTemp->_data == data)
        {
            return true;
        }
        pTemp = pTemp->_pNext;
    }
    return false;
}

void LinkedList::InterchangeSort()
{
    for(Node* i = _pHead; i->_pNext != nullptr; i = i->_pNext)
    {
        for(Node* j = i->_pNext; j != nullptr; j = j->_pNext)
        {
            if(i->_data > j->_data)
            {
                swap(i->_data, j->_data);
            }
        }
    }
}

void LinkedList::Hieu(LinkedList& lt1, LinkedList& lt2)
{
    Node* pTemp = lt1._pHead;
    while(pTemp != nullptr)
    {
        if(!lt2.contains(pTemp->_data))
        {
            this->addTail(pTemp->_data);
        }
        pTemp = pTemp->_pNext;
    }
}

void LinkedList::Giao(LinkedList& lt1, LinkedList& lt2)
{
    Node* pTemp = lt1._pHead;
    while(pTemp != nullptr)
    {
        if(lt2.contains(pTemp->_data))
        {
            this->addTail(pTemp->_data);
        }
        pTemp = pTemp->_pNext;
    }
}

void LinkedList::Hop(LinkedList& lt1, LinkedList& lt2)
{
    Node* pTemp = lt1._pHead;
    while(pTemp != nullptr)
    {
        this->addTail(pTemp->_data);
        pTemp = pTemp->_pNext;
    }
    Node* pTemp2 = lt2._pHead;
    while(pTemp2 != nullptr)
    {
        if(!this->contains(pTemp2->_data))
        {
            addTail(pTemp2->_data);
        }
        pTemp2 = pTemp2->_pNext;
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
        {
            break;
        }
    }
    int val1;
    while(cin >> val1)
    {
        L2.addTail(val1);
        if(cin.peek() == '\n')
        {
            break;
        }
    }
    cout << "Danh sach L1: ";
    L1.display();
    cout << "Danh sach L2: ";
    L2.display();
    //a
    /*
    L3.Hieu(L1, L2);
    */
    //b
    /*
    L3.Giao(L1, L2);
    */
    L3.Hop(L1, L2);
    cout << "Danh sach L3: ";
    L3.InterchangeSort();
    L3.display();
}