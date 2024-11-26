#include <iostream>
#include <cmath>

using namespace std;

class Node;
class LinkedList;
class DaThuc
{
    friend class Node;
    friend class LinkedList;
private:
    int heso;
    int mu;
public:
    DaThuc(int _heso = 0, int _mu = 0);
    friend istream& operator >> (istream& is, DaThuc& dt);
    DaThuc DaoHam();
    int TinhGT(int x);
    void display();
};

DaThuc::DaThuc(int _heso, int _mu)
{
    heso = _heso;
    mu = _mu;
}

istream& operator >> (istream& is, DaThuc& dt)
{
    is >> dt.heso;
    is >> dt.mu;
    return is;
}

DaThuc DaThuc::DaoHam()
{
    DaThuc ans;
    if(mu != 0)
    {
        ans.heso = heso * mu;
        ans.mu = mu - 1;
    }
    return ans;
}

int DaThuc::TinhGT(int x)
{
    return heso * pow(x, mu);
}

void DaThuc::display()
{
    if(heso != 0 && mu == 0)
    {
        cout << heso;
    }
    else if(heso == 1 && mu != 0)
    {
        cout << "x";
        if(mu != 1)
        {
            cout << "^" << mu;
        }
    }
    else if(heso == -1 && mu != 0)
    {
        cout << "-x";
        if(mu != 1)
        {
            cout << "^" << mu;
        }
    }
    else
    {
        if(heso != 0)
        {
            cout << heso;
            if(mu != 0)
            {
                cout << "x";
                if(mu != 1)
                {
                    cout << "^" << mu;
                }
            }
        }
    }
}

class LinkedList;
class Node
{
    friend LinkedList;
private:
    DaThuc _data;
    Node* _pNext;
public:
    Node(DaThuc data);
    void display();
};

Node::Node(DaThuc data)
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
    
    void addTail(DaThuc data);
    LinkedList Tong(LinkedList& lt2);
    LinkedList DH();
    void GT(int x);
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

void LinkedList::addTail(DaThuc data)
{
    Node* pWalker = _pHead;
    Node* pTemp = nullptr;
    while(pWalker != nullptr && pWalker->_data.mu > data.mu)
    {
        pTemp = pWalker;
        pWalker = pWalker->_pNext;
    }
    if(pWalker != nullptr && pWalker->_data.mu == data.mu)
    {
        pWalker->_data.heso += data.heso;
        if(pWalker->_data.mu == 0)
        {
            if(pTemp == nullptr)
            {
                _pHead = pWalker->_pNext;
            }
            else
            {
                pTemp->_pNext = pWalker->_pNext;
            }
            delete pWalker;
        }
    }
    else
    {
        Node* pAdd = new Node(data);
        if(pTemp == nullptr)
        {
            pAdd->_pNext = _pHead;
            _pHead = pAdd;
        }
        else
        {
            pAdd->_pNext = pTemp->_pNext;
            pTemp->_pNext = pAdd;
        }
    }
}

void LinkedList::display()
{
    Node* pTemp = _pHead;
    bool flag = true;
    while(pTemp != nullptr)
    {
        if(!flag && pTemp->_data.heso > 0)
        {
            cout << "+";
        }
        pTemp->display();
        flag = false;
        pTemp = pTemp->_pNext;
    }
}

LinkedList LinkedList::Tong(LinkedList& lt2)
{
    LinkedList res;
    Node* pTemp = _pHead;
    Node* pTemp2 = lt2._pHead;
    while(pTemp != nullptr || pTemp2 != nullptr)
    {
        if(pTemp == nullptr)
        {
            res.addTail(pTemp2->_data);
            pTemp2 = pTemp2->_pNext;
        }
        else if(pTemp2 == nullptr)
        {
            res.addTail(pTemp->_data);
            pTemp = pTemp->_pNext;
        }
        else if(pTemp->_data.mu > pTemp2->_data.mu)
        {
            res.addTail(pTemp->_data);
            pTemp = pTemp->_pNext;
        }
        else if(pTemp->_data.mu < pTemp2->_data.mu)
        {
            res.addTail(pTemp2->_data);
            pTemp2 = pTemp2->_pNext;
        }
        else
        {
            DaThuc ans;
            ans.heso = pTemp->_data.heso + pTemp2->_data.heso;
            ans.mu = pTemp->_data.mu;
            if(pTemp->_data.heso != 0)
            {
                res.addTail(ans);
            }
            pTemp = pTemp->_pNext;
            pTemp2 = pTemp2->_pNext;
        }
    }
    return res;
}

LinkedList LinkedList::DH()
{
    LinkedList res;
    Node* pTemp = _pHead;
    while(pTemp != nullptr)
    {
        DaThuc ans = pTemp->_data.DaoHam();
        if(ans.heso != 0)
        {
            res.addTail(ans);
        }
        pTemp = pTemp->_pNext;
    }
    return res;
}

void LinkedList::GT(int x)
{
    int s = 0;
    Node* pTemp = _pHead;
    while(pTemp != nullptr)
    {
        s += pTemp->_data.TinhGT(x);
        pTemp = pTemp->_pNext;
    }
    cout << s << '\n';
}

int main()
{
    LinkedList F1, F2;
    DaThuc x;
    while(cin >> x)
    {
        F1.addTail(x);
        if(cin.peek() == '\n') break;
    }
    DaThuc y;
    while(cin >> y)
    {
        F2.addTail(y);
        if(cin.peek() == '\n') break;
    }
    int a; 
    cin >> a;
    F1.display();
    cout << ' ';
    F2.display();
    cout << '\n';
    LinkedList F3 = F1.Tong(F2);
    LinkedList kq = F3.DH();
    kq.display();
    cout << '\n';
    LinkedList TinhGT = F1.Tong(F2);
    TinhGT.GT(a);
    LinkedList TinhTong = F1.Tong(F2);
    TinhTong.display();
}