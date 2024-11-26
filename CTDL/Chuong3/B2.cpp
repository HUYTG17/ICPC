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
    cout << _data << ' ';
}

class LinkedList
{
private:
    Node* _pHead;
    Node* _pTail;
    int _iSize;
public:
    LinkedList();

    void addTail(int data);
    void appendList(LinkedList other);
    Node* get_pHead();
    void Hieu(LinkedList lt1, LinkedList lt2);
    void Giao(LinkedList lt1, LinkedList lt2);
    void Hop(LinkedList lt1, LinkedList lt2);
    void SumList(LinkedList lt1, LinkedList lt2);
    void Sum();

    bool hasCommonValue(LinkedList lt1);
    bool contains(int data);

    void remove(int data);
    void removeFirst(LinkedList lt2);
    void removeAllMaxValue(LinkedList lt2);

    void display();
};

Node* LinkedList::get_pHead()
{
    return _pHead;
}

LinkedList::LinkedList()
{
    _pHead = nullptr;
    _pTail = nullptr;
    _iSize = 0;
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
}
 
void LinkedList::appendList(LinkedList other)
{
    Node* pTemp = other.get_pHead();
    while (pTemp != nullptr)
    {
        addTail(pTemp->_data);
        pTemp = pTemp->_pNext;
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

bool LinkedList::hasCommonValue(LinkedList lt1)
{
    Node* pTemp = lt1.get_pHead();
    while(pTemp != nullptr)
    {
        if(contains(pTemp->_data))
        {
            return true;
        }
        pTemp = pTemp->_pNext;
    }
    return false;
}

void LinkedList::Hieu(LinkedList lt1, LinkedList lt2)
{
    Node* pTemp = lt1.get_pHead();
    while(pTemp != nullptr)
    {
        if(!lt2.contains(pTemp->_data))
        {
            addTail(pTemp->_data);
        }
        pTemp = pTemp->_pNext;
    }
}

void LinkedList::Giao(LinkedList lt1, LinkedList lt2)
{
    Node* pTemp = lt1.get_pHead();
    while(pTemp != nullptr)
    {
        if(lt2.contains(pTemp->_data))
        {
            addTail(pTemp->_data);
        }
        pTemp = pTemp->_pNext;
    }
}

void LinkedList::Hop(LinkedList lt1, LinkedList lt2)
{
    Node* pTemp = lt1.get_pHead();
    while(pTemp != nullptr)
    {
        addTail(pTemp->_data);
        pTemp = pTemp->_pNext;
    }
    Node* pTemp2 = lt2.get_pHead();
    while(pTemp2 != nullptr)
    {
        if(!contains(pTemp2->_data))
        {
            addTail(pTemp2->_data);
        }
        pTemp2 = pTemp2->_pNext;
    }
}

void LinkedList::SumList(LinkedList lt1, LinkedList lt2)
{
    Node* pTemp = lt1.get_pHead();
    Node* pTemp2 = lt2.get_pHead();
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
        addTail(sum);
    }
}

void LinkedList::Sum()
{
    int sum = 0;
    Node* pTemp = _pHead;
    while(pTemp != nullptr)
    {
        sum += pTemp->_data;
        pTemp = pTemp->_pNext;
    }
    cout << sum;
}

void LinkedList::remove(int data)
{
    Node* pWalker = _pHead, *pTemp = nullptr;
    while(pWalker != nullptr && pWalker->_data != data)
    {
        pTemp = pWalker;
        pWalker = pWalker->_pNext;
    }
    if(pWalker == nullptr) return;
    if(pTemp != nullptr)
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
        delete pWalker;
        _iSize--;
    }
}

void LinkedList::removeFirst(LinkedList lt2)
{
    int sum = 0;
    Node* pTemp2 = lt2.get_pHead();
    while(pTemp2 != nullptr)
    {
        sum += pTemp2->_data;
        pTemp2 = pTemp2->_pNext;
    }
    Node* pTemp = _pHead;
    while(pTemp != nullptr)
    {
        if(pTemp->_data > sum)
        {
            remove(pTemp->_data);
            break;
        }
        else
        {
            pTemp = pTemp->_pNext;
        }
    }
}

void LinkedList::removeAllMaxValue(LinkedList lt2)
{
    int max = INT_MIN;
    Node* pTemp2 = lt2.get_pHead();
    while(pTemp2 != nullptr)
    {
        if(pTemp2->_data > max)
        {
            max = pTemp2->_data;
        }
        pTemp2 = pTemp2->_pNext;
    }
    Node* pTemp = _pHead;
    while(pTemp != nullptr)
    {
        if(pTemp->_data == max)
        {
            remove(pTemp->_data);
            pTemp = _pHead;
        }
        pTemp = pTemp->_pNext;
    }
}

int main()
{
    LinkedList L1, L2, L3;
    int n;
    cin >> n;
    /*
    //a
    for(int i = 0; i < n; ++i)
    {
       int val;
       cin >> val;
       L1.addTail(val);
    }
    for(int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        L2.addTail(val);
    }
    L3.appendList(L1);
    L3.appendList(L2);
    L3.display();
    */
    /*
    input 
    5
    1 2 3 4 5
    6 7 8 9 10
    output
    1 2 3 4 5 6 7 8 9 10
    */
    /*
    //b
    for(int i = 0; i < n; ++i)
    {
       int val;
       cin >> val;
       L1.addTail(val);
    }
    for(int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        L2.addTail(val);
    }
    L3.Hieu(L1, L2);
    L3.display();
    */
    /*
    input:
    5
    1 2 3 4 5
    1 2 3 6 7
    output
    4 5
    */
    /*
    //c
    for(int i = 0; i < n; ++i)
    {
       int val;
       cin >> val;
       L1.addTail(val);
    }
    for(int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        L2.addTail(val);
    }
    L3.Giao(L1, L2);
    L3.display();
    */
    /*
    input
    5
    1 2 3 5 4
    1 2 3 8 7
    output
    1 2 3*/
    /*
    //d
    for(int i = 0; i < n; ++i)
    {
       int val;
       cin >> val;
       L1.addTail(val);
    }
    for(int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        L2.addTail(val);
    }
    L3.Hop(L1, L2);
    L3.display();
    */
    /*
    input
    5
    1 2 3 4 5
    4 5 6 7 8
    output
    1 2 3 4 5 6 7 8
    */
    /*
    //e
    for(int i = 0; i < n; ++i)
    {
       int val;
       cin >> val;
       L1.addTail(val);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i)
    {
        int val;
        cin >> val;
        L2.addTail(val);
    }
    L3.SumList(L1, L2);
    L3.display();
    */
    /*
    input
    3
    1 2 3
    5
    4 5 6 7 8
    output
    5 7 9 7 8
    */
    /*
    //f
    for(int i = 0; i < n; ++i)
    {
       int val;
       cin >> val;
       L1.addTail(val);
    }
    for(int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        L2.addTail(val);
    }
    L2.hasCommonValue(L1) ? cout << "Trung gia tri" : cout << "Khong trung gia tri";
    */
    /*
    input
    5
    1 2 3 4 5
    4 6 7 8 9
    output
    Trung gia tri
    */
    //g
    /*
    for(int i = 0; i < n; ++i)
    {
       int val;
       cin >> val;
       L1.addTail(val);
    }
    for(int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        L2.addTail(val);
    }
    L1.removeFirst(L2);
    L1.display();
    */
    /*
    input
    5
    15 16 17 16 18
    1 2 3 4 5
    output
    15 17 16 18 
    */
    //h
    for(int i = 0; i < n; ++i)
    {
       int val;
       cin >> val;
       L1.addTail(val);
    }
    for(int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        L2.addTail(val);
    }
    L1.removeAllMaxValue(L2);
    L1.display();
    /*
    input
    5
    5 8 9 8 7
    0 5 3 8 2
    output
    5 9 7
    */
}