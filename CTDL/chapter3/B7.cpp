#include <bits/stdc++.h>

using namespace std;

class Node;
class LinkedList;
class DaThuc
{
    friend class Node;
    friend class LinkedList;
private:
    int coefficient;
    int exponent;
public:
    DaThuc() : coefficient(0), exponent(0) {}
    friend istream& operator >> (istream& is, DaThuc &dt);
    void display();
};

istream& operator >> (istream& is, DaThuc &dt)
{
    is >> dt.coefficient;
    is >> dt.exponent;
    return is;
}

void DaThuc::display()
{
    if(exponent == 0 && coefficient != 0)
    {
        cout << coefficient;
    }
    else if(coefficient == 1 && exponent != 0)
    {
        cout << "x";
        if(exponent != 1)
        {
            cout << "^" << exponent;
        }
    }
    else if(coefficient == -1 && exponent != 0)
    {
        cout << "-x";
        if(exponent != 1)
        {
            cout << "^" << exponent;
        }
    }
    else
    {
        if(coefficient != 0)
        {
            cout << coefficient;
            if(exponent != 0)
            {
                cout << "x";
                if(exponent != 1)
                {
                    cout << "^" << exponent;
                }
            }
        }
    }
}

class Node
{
    friend class LinkedList;
private:
    DaThuc _data;
    Node* _pNext;
public:
    Node(DaThuc data) : _data(data), _pNext(nullptr) {}
    void display();
};

void Node::display()
{
    _data.display();
}

class LinkedList
{
private:
    Node* _pHead;
    Node* _pTail;
public:
    LinkedList() : _pHead(nullptr), _pTail(nullptr) {}
    
    void add(DaThuc data);
    void display();
};

void LinkedList::display()
{
    Node* pTemp = _pHead;
    while(pTemp != nullptr)
    {
        pTemp->display();
        if(pTemp->_pNext && pTemp->_data.coefficient > 0) 
        {
            cout << '+';
        }
        pTemp = pTemp->_pNext;
    }
    cout << ' ';
}

void LinkedList::add(DaThuc data)
{
    Node* Temp = _pHead;
    Node* prev = nullptr;
    while(Temp != nullptr && Temp->_data.exponent > data.exponent)
    {
        prev = Temp;
        Temp = Temp->_pNext;
    }
    if(Temp != nullptr && Temp->_data.exponent == data.exponent)
    {
        Temp->_data.exponent += data.exponent;
        if(Temp->_data.exponent == 0)
        {
            if(prev == nullptr)
            {
                _pHead = Temp->_pNext;
            }
            else
            {
                prev->_pNext = Temp->_pNext;
            }
            delete Temp;
        }
    }
    else
    {
        Node* pAdd = new Node(data);
        if(prev == nullptr)
        {
            pAdd->_pNext = _pHead;
            _pHead = pAdd;
        }
        else
        {
            pAdd->_pNext = prev->_pNext;
            prev->_pNext = pAdd;
        }
    }
}

int main()
{
    DaThuc a, a1;
    LinkedList L1, L2;
    while(cin >> a)
    {
        L1.add(a);
        if(cin.peek() == '\n')
            break;
    }
    L1.display();
    while(cin >> a1)
    {
        L2.add(a1);
        if(cin.peek() == '\n')
            break;
    }
    L2.display();
}