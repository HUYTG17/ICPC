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
    void display()
    {
        cout << _data;
    }
};

class LinkedList
{
private:
    Node* _pHead;
    Node* _pTail;
    int _iSize;
public:
    LinkedList() : _pHead(nullptr), _pTail(nullptr), _iSize(0) {}
    ~LinkedList()
    {
        while(_pHead != nullptr)
        {
            Node* pTemp = _pHead;
            _pHead = _pHead->_pNext;
            delete pTemp;
        }
    }
    void addTail(int data)
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
    int getSize()
    {
        return _iSize;
    }
    void display()
    {
        Node* pTemp = _pHead;
        while(pTemp != nullptr)
        {
            pTemp->display();
            if(pTemp->_pNext) cout << ' ';
            pTemp = pTemp->_pNext;
        }
    }
    bool contains(int data)
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
    void interchangeSortInCrease()
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
    void interchangeSortDeCrease()
    {
        for(Node* i = _pHead; i->_pNext != nullptr; i = i->_pNext)
        {
            for(Node* j = i->_pNext; j != nullptr; j = j->_pNext)
            {
                if(i->_data < j->_data)
                {
                    swap(i->_data, j->_data);
                }
            }
        }
    }
    LinkedList Hop(LinkedList &other)
    {
        LinkedList res;
        Node* pTemp = _pHead;
        while(pTemp != nullptr)
        {
            res.addTail(pTemp->_data);
            pTemp = pTemp->_pNext;
        }
        Node* pTemp2 = other._pHead;
        while(pTemp2 != nullptr)
        {
            if(!res.contains(pTemp2->_data))
            {
                res.addTail(pTemp2->_data);
            }
            pTemp2 = pTemp2->_pNext;
        }
        return res;
    }
    LinkedList Hieu(LinkedList &other)
    {
        LinkedList res;
        Node* pTemp = _pHead;
        while(pTemp != nullptr)
        {
            if(!other.contains(pTemp->_data))
            {
                res.addTail(pTemp->_data);
            }
            pTemp = pTemp->_pNext;
        }
        return res;
    }
    void solveTwo()
    {
        int mid = _iSize / 2;
        LinkedList lt1, lt2;
        Node* pTemp = _pHead;
        int cnt = 0;
        while(pTemp != nullptr)
        {
            if(cnt < mid)
            {
                lt1.addTail(pTemp->_data);
            }
            else
            {
                lt2.addTail(pTemp->_data);
            }
            cnt++;
            pTemp = pTemp->_pNext;
        }
        lt1.interchangeSortDeCrease();
        lt2.interchangeSortInCrease();
        lt1.display();
        cout << ' ';
        lt2.display();
    }
    LinkedList Sum(LinkedList &other)
    {
        LinkedList lt1;
        Node* pTemp = _pHead;
        Node* pTemp2 = other._pHead;
        while(pTemp != nullptr || pTemp2 != nullptr)
        {
            int sum = 0;
            if(pTemp != nullptr)
            {
                sum += pTemp->_data;
                pTemp = pTemp->_pNext;
            }
            if(pTemp2 != nullptr)
            {
                sum += pTemp2->_data;
                pTemp2 = pTemp2->_pNext;
            }
            lt1.addTail(sum);
        }
        return lt1;
    }
};

int main()
{
    LinkedList L1, L2;
    int x;
    while(cin >> x)
    {
        L1.addTail(x);
        if(cin.peek() == '\n') break;
    }
    int y;
    while(cin >> y)
    {
        L2.addTail(y);
        if(cin.peek() == '\n') break;
    }
    LinkedList L3 = L1.Hop(L2);
    L3.interchangeSortDeCrease();
    L3.display();
    cout << '\n';
    LinkedList L4 = L1.Hieu(L2);
    L4.solveTwo();
    cout << '\n';
    LinkedList L5 = L1.Sum(L2);
    L5.display();
    return 0;
}