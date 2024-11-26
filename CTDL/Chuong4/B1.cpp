#include <bits/stdc++.h>

using namespace std;

class Stack;
class Node
{   
    friend class Stack;
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

class Stack
{
private:
    Node* _pTop;
    int _iSize;
public:
    Stack() : _pTop(nullptr), _iSize(0) {}
    ~Stack();
    
    bool isEmpty();
    void push(int data);
    int pop();
    int peek();
    void display();
    int getSize();
    void convertToBinary(int n);
};

bool Stack::isEmpty()
{
    return (_pTop == nullptr);
}

void Stack::push(int data)
{
    Node* pAdd = new Node(data);
    pAdd->_pNext = _pTop;
    _pTop = pAdd;
    _iSize++;
}

int Stack::pop()
{
    if(isEmpty())
    {
        cout << "Stack rong!!!";
        return 0;
    }
    Node* pTemp = _pTop;
    int temp = pTemp->_data;
    _pTop = pTemp->_pNext;
    delete pTemp;
    _iSize--;
    return temp;
}

int Stack::peek()
{
    if(isEmpty())
    {
        cout << "Stack rong!!!";
        return 0;
    }
    return _pTop->_data;
}

void Stack::display()
{
    if(isEmpty())
    {
        cout << "Stack rong!!!";
    }
    Node* pTemp = _pTop;
    while(pTemp != nullptr)
    {
        pTemp->display();
        pTemp = pTemp->_pNext;
    }
    cout << '\n';
}

int Stack::getSize()
{
    return _iSize;
}

void Stack::convertToBinary(int n)
{
    if(n == 0)
    {
        cout << 0;
        return;
    }
    while(n != 0)
    {
        push(n % 2);
        n /= 2;
    }
    while(!isEmpty())
    {
        cout << pop();
    }
}

Stack::~Stack()
{
    while(_pTop != nullptr)
    {
        Node* p = _pTop;
        _pTop = _pTop->_pNext;
        delete p;
    }
    _iSize = 0;
}

int main()
{
    Stack st;
    int n;
    cin >> n;
    st.convertToBinary(n);
}