#include <iostream>

using namespace std;

class LinkedList;
class Node
{
    friend class LinkedList;
private:
    int _data;
    Node* _pNext;
public:
    Node(int data);
    void display();
};

Node::Node(int data)
{
    _data = data;
    _pNext = nullptr;
}

void Node::display()
{
    cout << _data;
}

class LinkedList
{
private:
    Node* _pHead;
    Node* _pTail;
public:
    LinkedList();
    ~LinkedList();
    
    void addTail(int data);
    bool contains(int data);
    LinkedList Hop(LinkedList& lt2);
    void interchangeSort();
    LinkedList find(LinkedList& lt2);
    void remove(int data);
    LinkedList removemin(LinkedList& lt2);
    void display();
};

LinkedList::LinkedList()
{
    _pHead = nullptr;
    _pTail = nullptr;
}

LinkedList::~LinkedList()
{
    while(_pHead != nullptr)
    {
        Node* pTemp = _pHead;
        _pHead = _pHead->_pNext;
        delete pTemp;
    }
}

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

LinkedList LinkedList::Hop(LinkedList& lt2)
{
    LinkedList res;
    Node* pTemp = _pHead;
    while(pTemp != nullptr)
    {
        if(lt2.contains(pTemp->_data) && !res.contains(pTemp->_data))
        {
                res.addTail(pTemp->_data);
        }
        pTemp = pTemp->_pNext;
    }
    return res;
}

void LinkedList::interchangeSort()
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

LinkedList LinkedList::find(LinkedList& lt2)
{
    LinkedList res;
    Node* p1 = _pHead;
    while(p1 != nullptr)
    {
        Node* p2 = lt2._pHead;
        Node* start = p1;
        while(p2 != nullptr)
        {
            Node* pTemp1 = start;
            Node* pTemp2 = p2;
            while(p1 != nullptr && p2 != nullptr && p1->_data == p2->_data)
            {
                res.addTail(p1->_data);
                p1 = p1->_pNext;
                p2 = p2->_pNext;
            }
            if(res._pHead != nullptr) return res;
            p2 = p2->_pNext;
        }
        p1 = p1->_pNext;
    }
}

void LinkedList::remove(int data)
{
    Node* pWalker = _pHead, *pTemp = nullptr;
    while(pWalker != nullptr && pWalker->_data != data)
    {
        pTemp = pWalker;
        pWalker = pWalker->_pNext;
    }
    if(pWalker == _pHead)
    {
        _pHead = _pHead->_pNext;
        if(_pHead == nullptr)
            _pTail = nullptr;
    }
    else
    {
        if(pWalker == _pTail)
        {
            _pTail = pTemp;
            _pTail->_pNext = nullptr;
        }
        else
        {
            pTemp->_pNext = pWalker->_pNext;
        }
    }
    delete pWalker;
}

LinkedList LinkedList::removemin(LinkedList& lt2)
{
    Node* pTemp2 = lt2._pHead;
    int min = 999999;
    while(pTemp2 != nullptr)
    {
        if(min > pTemp2->_data)
        {
            min = pTemp2->_data;
        }
        pTemp2 = pTemp2->_pNext;
    }
    Node* pTemp = _pHead;
    while(pTemp != nullptr)
    {
        if(pTemp->_data == min)
        {
            remove(pTemp->_data);
            pTemp = _pHead;
        }
        pTemp = pTemp->_pNext;
    }
    return *this;
}

void LinkedList::display()
{
    Node* pTemp = _pHead;
    while(pTemp != nullptr)
    {
        pTemp->display();
        if(pTemp->_pNext) cout << ' ';
        pTemp = pTemp->_pNext;
    }
}

int main()
{
    LinkedList L1, L2;
    int a;
    while(cin >> a)
    {
        L1.addTail(a);
        if(cin.peek() == '\n') break;
    }
    int b;
    while(cin >> b)
    {
        L2.addTail(b);
        if(cin.peek() == '\n') break;
    }
    LinkedList L3 = L1.Hop(L2);
    L3.interchangeSort();
    L3.display();
    cout << '\n';
    LinkedList L4 = L1.find(L2);
    L4.display();
    cout << '\n';
    LinkedList L5 = L1.removemin(L2);
    L5.display();
}