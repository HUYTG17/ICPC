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
public:   
    Stack() : _pTop(nullptr) {}
    ~Stack();
    
    bool isEmpty();
    void push(int data);
    int pop();
    int peek();
    void TinhGiaTri(string s);
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

void Stack::TinhGiaTri(string a)
{
    stringstream ss(a);
    string s;
    while(ss >> s)
    {
        if(isdigit(s[0]) || s[0] == '-' && s.size() > 1)
        {
            push(stoi(s));
        }
        else
        {
            int val1 = pop();
            int val2 = pop();
            switch(s[0])
            {
                case '+' : push(val2 + val1); break;
                case '-' : push(val2 - val1); break;
                case '*' : push(val2 * val1); break;
                case '/' : push(val2 / val1); break;
            }
        }
    }
    cout << pop();
}


Stack::~Stack()
{
    while(_pTop != nullptr)
    {
        Node* pTemp = _pTop;
        _pTop = _pTop->_pNext;
        delete pTemp;
    }
}

int main()
{
    Stack st;
    string s;
    getline(cin, s);
    st.TinhGiaTri(s);
}