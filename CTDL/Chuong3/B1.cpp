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
    Node(int _data);
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
    ~LinkedList();

    void addHead(int data);
    void addTail(int data);
    void addAfter(Node* node, int data);
    void addUnique(int data);
    Node* search(int data);
    Node* searchPre(Node* node);

    void removeHeadK(int k);
    void removeHead();
    void removeTail();
    void remove(int data);
    void removeAfter(Node* node);

    void selectionSort();
    void interchangeSort();
    void Sht();

    int getSize();
    int sum();
    int count(int a);
    int Scp();
    int findValue(int k);
    int min();
    void display();
    void clear();
};

LinkedList::LinkedList()
{
    _pHead = nullptr;
    _pTail = nullptr;
    _iSize = 0;
}

LinkedList::~LinkedList()
{
    clear();
}

void LinkedList::addHead(int data)
{
    Node* pAdd = new Node(data);
    if(_pHead == nullptr)
    {
        _pHead = _pTail = pAdd;
    }
    else
    {
        pAdd->_pNext = _pHead;
        _pHead = pAdd;
    }
    _iSize++;
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
    Node* temp = _pHead;
    while(temp != nullptr)
    {
        temp->display();
        temp = temp->_pNext;
    }
}

bool isPrime(int n)
{
    if(n < 2) return false;
    for(int i = 2; i * i <= n; ++i)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int LinkedList::getSize()
{
    return _iSize;
}

int LinkedList::sum()
{
    int sum = 0;
    Node* temp = _pHead;
    while(temp != nullptr)
    {
        sum += temp->_data;
        temp = temp->_pNext;
    }
    return sum / getSize();
}

int LinkedList::count(int a)
{
    int cnt = 0;
    Node* temp = _pHead;
    while(temp != nullptr)
    {
        if(temp->_data == a)
        {
            ++cnt;
        }
        temp = temp->_pNext;
    }
    return cnt;
}

bool scp(int n)
{
    int kq = sqrt(n);
    if(kq * kq == n) return true;
    return false;
}

int LinkedList::Scp()
{
    Node* temp = _pHead;
    int ans = 0;
    while(temp != nullptr)
    {
        if(scp(temp->_data))
        {
            ans = temp->_data;
        }
        temp = temp->_pNext;
    }
    return ans;
}

int LinkedList::findValue(int k)
{
    Node* temp = _pHead;
    int pos = 0, ans = 0;
    while(temp != nullptr)
    {
        if(pos == k)
        {
            ans = temp->_data;
        }
        temp = temp->_pNext;
        pos++;
    }
    return ans;
}

int LinkedList::min()
{
    Node* temp = _pHead;
    int Min = INT_MAX;
    while(temp != nullptr)
    {
        if(Min > temp->_data)
        {
            Min = temp->_data;
        }
        temp = temp->_pNext;
    }
    return Min;
}

void LinkedList::addAfter(Node* node, int data)
{
    Node* pAdd = new Node(data);
    if(node != nullptr)
    {
        pAdd->_pNext = node->_pNext;
        node->_pNext = pAdd;
        if(node == _pTail)
            _pTail = pAdd;
    }
    else
    {
        addHead(data);
    }
    _iSize++;
}

Node* LinkedList::search(int data)
{
    Node* p = _pHead;
    while((p != nullptr) && (p->_data != data))
        p = p->_pNext;
    return p;
}

void LinkedList::addUnique(int data)
{
    if(search(data) == nullptr)
    {
        addTail(data);
    }
    else
    {
        cout << "Phan tu " << data << " da ton tai trong danh sach\n";
    }
    _iSize++;
}

void LinkedList::removeHeadK(int k)
{
    while(k > 0 && _pHead != nullptr)
    {
        Node* temp = _pHead;
        _pHead = _pHead->_pNext;
        delete temp;
        _iSize--;
        k--;
    }
    if(_pHead == nullptr)
    {
        _pTail = nullptr;
    }
}

void LinkedList::remove(int data)
{
    Node* pWalker = _pHead, *pTemp = nullptr;
    while((pWalker != nullptr) && (pWalker->_data != data))
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

Node* LinkedList::searchPre(Node* node)
{
    Node* p = _pHead;
    if(p == node)
        return nullptr;
    while((p != nullptr) && (p->_pNext != node))
        p = p->_pNext;
    return p;
}

void LinkedList::removeHead()
{
    if(_pHead != nullptr)
    {
        Node* pTemp = _pHead;
        _pHead = _pHead->_pNext;
        delete pTemp;
        if(_pHead == nullptr)
            _pTail = nullptr;
        _iSize--;
    }
}

void LinkedList::removeTail()
{
    if(_pHead == nullptr)
        return;
    Node* pTemp = _pTail;
    _pTail = searchPre(_pTail);
    delete pTemp;
    if(_pTail != nullptr)
    {
        _pTail->_pNext = nullptr;
    }
    else
    {
        _pHead = nullptr;
    }
    _iSize--;
}

void LinkedList::removeAfter(Node* node)
{
    Node* pTemp;
    if(node != nullptr)
    {
        pTemp = node->_pNext;
        if(pTemp != nullptr)
        {
            if(pTemp == _pTail);
                _pTail = node;
            node->_pNext = pTemp->_pNext;
            delete pTemp;
        }
    }
    else
    {
        removeHead();
    }
    _iSize--;
}

void LinkedList::clear()
{
    while(_pHead != nullptr)
    {
        removeHead();
    }
}

void LinkedList::selectionSort()
{
    Node* min;
    for(Node* i = _pHead; i->_pNext != nullptr; i = i->_pNext)
    {
        min = i;
        for(Node* j = i->_pNext; j != nullptr; j = j->_pNext)
            if(min->_data > j->_data)
                min = j;
        swap(min->_data, i->_data);
    }
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
bool sht(int n)
{
    int sum = 0;
    for(int i = 1; i < n; ++i)
    {
        if(n % i == 0)
        {
            sum += i;
        }
    }
    if(sum == n) return true;
    else return false;
}

void LinkedList::Sht()
{
    Node* pTemp  = _pHead;
    while(pTemp != nullptr)
    {
        if(sht(pTemp->_data))
        {
            pTemp->_data = 0;
        }
        pTemp = pTemp->_pNext;
    }
}

int main()
{
    LinkedList list;
    int n, val, a;
    cin >> n;
    //a
    /*
    for(int i = 0; i < n; ++i)
    {
        cin >> val;
        list.addTail(val);
    }
    */
    /*
    //b
    list.display();
    */
    /*
    //c
    for(int i = 0; i < n; ++i)
    {
        cin >> val;
        if(isPrime(val))
        {
            list.addTail(val);
        }
    }
    list.display();
    */
    /*
    //d
    for(int i = 0; i <  n; ++i)
    {
        cin >> val;
        list.addTail(val);
    }
    cout << list.sum();
    */
    //e
    /*
    cin >> a;
    for(int i = 0; i <  n; ++i)
    {
        cin >> val;
        list.addTail(val);
    }
    cout << list.count(a);
    */
    //f
    /*
    for(int i = 0; i <  n; ++i)
    {
        cin >> val;
        list.addTail(val);
    }
    cout << list.Scp();
    */
    //g
    /*
    int k;
    cin >> k;
    for(int i = 0; i < n; ++i)
    {
        cin >> val;
        list.addTail(val);
    }
    cout << list.findValue(k);
    */
    //h
    /*
    for(int i = 0; i < n; ++i)
    {
        cin >> val;
        list.addTail(val);
    }
    cout << list.min();
    */
    //i
    /*
    int q, k;
    cin >> q >> k;
    for(int i = 0; i < n; ++i)
    {
        cin >> val;
        list.addTail(val);
    }
    Node* Before = list.search(q);
    list.addAfter(After, k);
    list.display();
    */
    // input
    /*
    4 2 16
    1 16 2 4
    output
    1 16 2 16 4  */
    //j
    /*
    for(int i = 0; i < n; ++i)
    {
        cin >> val;
        list.addUnique(data);
    }
    list.display();
    intput 
    5
    1 2 2 3 3 
    out 
    1 2 3
    */
    //k;
    /*
    int k;
    cin >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> val;
        list.addTail(val);
    }
    list.removeHeadK(k);
    list.display();
    input
    5 3
    1 2 3 4 5
    output
    4 5
    */
    //l
    /*
    int x;
    cin >> x;
    for(int i = 0; i < n; i++)
    {
        cin >> val;
        list.addTail(val);
    }
    list.remove(x);
    list.display();
    */
    /*
    //m
    int q;
    cin >> q;
    for(int i = 0; i < n; i++)
    {
        cin >> val;
        list.addTail(val);
    }
    Node* Before = list.search(q);
    list.removeAfter(Before);
    list.display();
    */
    /*
    //n
    for(int i = 0; i < n; i++)
    {
        cin >> val;
        list.addUnique(val);
    }
    list.display();
    */
    /*
    //o
    for(int i = 0; i < n; i++)
    {
        cin >> val;
        list.addTail(val);
    }
    list.interchangeSort();
    list.display();
    */
    /*
    //p
    for(int i = 0; i < n; i++)
    {
        cin >> val;
        list.addTail(val);
    }
    int k;
    cin >> k;
    list.addTail(k);
    list.selectionSort();
    list.display();
    */
    //q
    for(int i = 0; i < n; i++)
    {
        cin >> val;
        list.addTail(val);
    }
    list.Sht();
    list.display();
}