#include <bits/stdc++.h>

using namespace std;

class Stack;
class Node
{
    friend class Stack;
private:
    char _data;
    Node* _pNext;
public:
    Node(char data) : _data(data), _pNext(nullptr) {}
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
    void push(char data);
    char pop();
    bool check(string s);
};

bool Stack::isEmpty()
{
    return (_pTop == nullptr);
}

void Stack::push(char data)
{
    Node* pAdd = new Node(data);
    pAdd->_pNext = _pTop;
    _pTop = pAdd;
}

char Stack::pop()
{
    if(isEmpty())
    {
        cout << "Stack rong!!!";
        return 0;
    }
    Node* pTemp = _pTop;
    char temp = pTemp->_data;
    _pTop = pTemp->_pNext;
    delete pTemp;
    return temp;
}

bool Stack::check(string s)
{
    for(char c : s)
    {
        if(c == '(' || c == '[' || c == '{')
        {
            push(c);
        }
        else
        {
            if(isEmpty())
            {
                return false;
            }
            else
            {
                char top = pop();
                if(c == ')' && top != '(' || c == ']' && top != '[' 
                || c == '}' && top != '{')
                {
                    return false;
                }
            }
        }
    }
    return isEmpty();
}

Stack::~Stack()
{
    while(_pTop != nullptr)
    {
        Node* p = _pTop;
        _pTop = _pTop->_pNext;
        delete p;
    }
}

int main()
{
    Stack st;
    string s;
    cin >> s;
    cout << (st.check(s) ? "true" : "false");
}