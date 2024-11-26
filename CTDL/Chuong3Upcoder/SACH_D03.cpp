#include <iostream>

using namespace std;

class LinkedList;
class Node;
class SACH
{
    friend class LinkedList;
    friend class Node;
private:
    string Ma;
    string Ten;
    int SoTo;
public:
    SACH();
    friend istream& operator >> (istream& is, SACH& s);
    void display();  
};

SACH::SACH()
{
    Ma = "";
    Ten = "";
    SoTo = 0;
}

istream& operator >> (istream& is, SACH& s)
{
    is.ignore();
    is >> s.Ma;
    is >> s.Ten;
    is >> s.SoTo;
    return is;
}

void SACH::display()
{
    cout << Ma << '-' << Ten << '-' << SoTo;    
}

class LinkedList;
class Node
{
    friend class LinkedList;
private:
    SACH _data;
    Node* _pNext;
public:
    Node(SACH data);
    void display();
};

Node::Node(SACH data)
{
    _data = data;
    _pNext = nullptr;
}

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
    LinkedList();
    ~LinkedList();
    
    void addTail(SACH data);
    void remove(int k);
    void SumSoTo();
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

void LinkedList::addTail(SACH data)
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

void LinkedList::remove(int k)
{
    if(k == 0)
    {
        Node* pTemp = _pHead;
        _pHead = _pHead->_pNext;
        if(_pHead == nullptr)
            _pTail = nullptr;
        delete pTemp;
        return;
    }
    Node* prev = nullptr;
    Node* pTemp = _pHead;
    int cnt = 0;
    while(pTemp != nullptr && cnt < k)
    {
        prev = pTemp;
        pTemp = pTemp->_pNext;
        cnt++;
    }
    if(pTemp != nullptr)
    {
        if(pTemp == _pTail)
        {
            _pTail = prev;
            _pTail->_pNext = nullptr;
        }
        else
        {
            prev->_pNext = pTemp->_pNext;
        }
        delete pTemp;
    }
}

void LinkedList::SumSoTo()
{
    Node* pTemp = _pHead;
    int sum = 0;
    while(pTemp != nullptr)
    {
        sum += pTemp->_data.SoTo;
        pTemp = pTemp->_pNext;
    }
    cout << sum << '\n';
}

void LinkedList::display()
{
    Node* pTemp = _pHead;
    while(pTemp != nullptr)
    {
        pTemp->display();
        if(pTemp->_pNext) cout << '\n';
        pTemp = pTemp->_pNext;
    }
}

int main()
{
    int n, k; cin >> n >> k;
    LinkedList l1;
    SACH a;
    for(int i = 0; i < n; ++i)
    {
        cin >> a;
        l1.addTail(a);
    }
    l1.SumSoTo();
    l1.remove(k);
    l1.display();
    return 0;
}