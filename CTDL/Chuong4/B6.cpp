#include <bits/stdc++.h>

using namespace std;

class Node;
class Queue;
class HangHoa
{
    friend class Node;
    friend class Queue;
private:
    string Ma;
    string Ten;
    int soluong;
    int gia;
public:
    HangHoa(string _Ma = "", string _Ten = "", int _sl = 0, int _gia = 0);
    friend istream& operator >> (istream& is, HangHoa &hh);
    void display();
};

HangHoa::HangHoa(string _Ma, string _Ten, int _sl, int _gia)
{
    Ma = _Ma;
    Ten = _Ten;
    soluong = _sl;
    gia = _gia;
}

istream& operator >> (istream& is, HangHoa &hh)
{
    is.ignore();
    is >> hh.Ma;
    is.ignore();
    getline(is, hh.Ten);
    is >> hh.soluong;
    is >> hh.gia;
    return is;
}

void HangHoa::display()
{
    cout << "Ten hang: " << Ten << '\n';
    cout << "Ma hang: " << Ma << '\n';
    cout << "So luong: " << soluong << '\n';
    cout << "Gia: " << gia << '\n';
}

class Queue;
class Node
{
    friend class Queue;
private:
    HangHoa _data;
    Node* _pNext;
public:
    Node(HangHoa data);
    void display();
};

Node::Node(HangHoa data)
{
    _data = data;
    _pNext = nullptr;
}

void Node::display()
{
    _data.display();
}

class Queue
{
private:
    Node* _pFront;
    Node* _pRear;
    int _iSize;
public:
    Queue();
    ~Queue();
    
    bool isEmpty();
    void enQue(HangHoa data);
    HangHoa deQue();
    HangHoa peek();
    void display();
    int getSize();
};

Queue::Queue()
{
    _pFront = nullptr;
    _pRear = nullptr;
    _iSize = 0;
}

Queue::~Queue()
{
    while(_pFront != nullptr)
    {
        Node* pTemp = _pFront;
        _pFront = _pFront->_pNext;
        delete pTemp;
    }
    _iSize = 0;
}

bool Queue::isEmpty()
{
    return (_pFront == nullptr);
}

void Queue::enQue(HangHoa data)
{
    Node* pAdd = new Node(data);
    if(_pFront == nullptr)
    {
        _pFront = _pRear = pAdd;
    }
    else
    {
        _pRear->_pNext = pAdd;
        _pRear = pAdd;
    }
    _iSize++;
}

HangHoa Queue::deQue()
{
    if(isEmpty())
    {
        cout << "Queue rong!!!";
        exit;
    }
    Node* pTemp = _pFront;
    HangHoa temp = pTemp->_data;
    _pFront = pTemp->_pNext;
    delete pTemp;
    _iSize--;
    if(_pFront == nullptr)
        _pRear = nullptr;
    return temp;
}

HangHoa Queue::peek()
{
    if(isEmpty())
    {
        cout << "Stack rong!!!";
        exit;
    }
    return _pFront->_data;
}

void Queue::display()
{
    if(isEmpty())
    {
        cout << "Queue rong!!!";
        exit;
    }
    Node* pTemp = _pFront;
    while(pTemp != nullptr)
    {
        pTemp->display();
        pTemp = pTemp->_pNext;
    }
}

int Queue::getSize()
{
    return _iSize;
}

int main()
{
    Queue qe;
    int n;
    cin >> n;
    HangHoa a;
    for(int i = 0; i < n; ++i)
    {
        cin >> a;
        qe.enQue(a);
    }
    //c
    //qe.display();
    //d
    // HangHoa a1 = qe.peek();
    // a1.display();
    //e
    // HangHoa b;
    // cin >> b;
    // qe.enQue(b);
    // qe.display();
    //f
    HangHoa a3 = qe.deQue();
    a3.display();
    return 0;
}

/*
3
Keo01
Keo Mut
10
10000
Keo02
KeoSua
10000
2000000000
Keo04
Keo Ngot
100
300000000
Keo03
Keo Chua
15
500000
*/