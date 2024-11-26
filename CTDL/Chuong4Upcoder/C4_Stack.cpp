#include <iostream>
#include <sstream>

using namespace std;

class Stack;
class Node
{
    friend class Stack;
private:
    char _data;
    Node* _pNext;
public:
    Node(char data);
    void display();
};

Node::Node(char data)
{
    _data = data;
    _pNext = nullptr;
}

class Stack
{
private:
    Node* _pTop;
public:
    Stack();
    ~Stack();
    
    bool isEmpty();
    void push(char data);
    int pop1();
    char pop();
    char peek();
    string intoPost(string s);
    void GT(string s);
};

Stack::Stack()
{
    _pTop = nullptr;
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
    
bool Stack::isEmpty()
{
    return _pTop == nullptr;
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
        cout << "Stack rong!!!\n";
        return 0;
    }
    Node* pTemp = _pTop;
    char temp = pTemp->_data;
    _pTop = pTemp->_pNext;
    delete pTemp;
    return temp;
}

int Stack::pop1()
{
    if(isEmpty())
    {
        cout << "Stack rong!!!\n";
        return 0;
    }
    Node* pTemp = _pTop;
    int temp = pTemp->_data;
    _pTop = pTemp->_pNext;
    delete pTemp;
    return temp;
}

char Stack::peek()
{
    if(isEmpty())
    {
        cout << "Stack rong!!!\n";
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

string Stack::intoPost(string s)
{
    string ans;
    for(char c : s)
    {
        if(isdigit(c))
        {
            ans += c;
        }
        else if(c == '(')
        {
            push(c);
        }
        else if(c == ')')
        {
            while(!isEmpty() && peek() != '(')
            {
                ans += ' ';
                ans += pop();
            }
            pop();
        }
        else 
        {
            ans += ' ';
            while(!isEmpty() && uutien(peek()) >= uutien(c))
            {
                ans += pop();
                ans += ' ';
            }
            push(c);
        }
    }
    while(!isEmpty())
    {
        ans += ' ';
        ans += pop();
    }
    return ans;
}

void Stack::GT(string s)
{
    stringstream ss(s);
    string s1;
    while(ss >> s1)
    {
        if(isdigit(s1[0]))
        {
            push(stoi(s1));
        }
        else
        {
            int a = pop1();
            int b = pop1();
            switch(s1[0])
            {
                case '+': push(b + a); break;
                case '-': push(b - a); break;
                case '*': push(b * a); break;
                case '/': push(b / a); break;
            }
        }
    }
    cout << pop1();
}

int main()
{
    Stack st;
    string s;
    cin >> s;
    string kq = st.intoPost(s);
    cout << kq << '\n';
    st.GT(kq);
}