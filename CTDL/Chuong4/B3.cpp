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
    char peek();
    void infixToPostFix(string s);
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

char Stack::peek()
{
    if(isEmpty())
    {
        cout << "Stack rong!!!";
        return 0;
    }
    return _pTop->_data;
}

int uutien(char c)
{
    if(c == '^')
        return 3;
    if(c == '*' || c == '/')
        return 2;
    if(c == '+' || c == '-')
        return 1;
    return 0;
}

void Stack::infixToPostFix(string s)
{
    string str;
    for(auto c : s)
    {
        if(isalnum(c))
        {
            str += c;
        }
        else if(c == '(')
        {
            push(c);
        }
        else if(c == ')')
        {
            while(!isEmpty() && peek() != '(')
            {
                str += pop();
            }
            pop();
        }
        else
        {
            while(!isEmpty() && uutien(peek()) >= uutien(c))
            {
                str += pop();
            }
            push(c);
        }
    }
    while(!isEmpty())
    {
        str += pop();
    }
    for(auto c : str)
    {
        cout << c << ' ';
    }
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
    cin >> s;
    st.infixToPostFix(s);
    return 0;
}
