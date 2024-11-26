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
    DaThuc(int c = 0, int e = 0) : coefficient(c), exponent(e) {}
    friend istream& operator >> (istream& is, DaThuc &dt);
    DaThuc DaoHam();
    int tinhGiaTri(int x);
    void display();
};

istream& operator >> (istream& is, DaThuc &dt)
{
    is >> dt.coefficient;
    is >> dt.exponent;
    return is;
}

DaThuc DaThuc::DaoHam()
{
    DaThuc a;
    if(exponent != 0)
    {
        a.coefficient = exponent * coefficient;
        a.exponent = exponent - 1;
    }
    return a;
}

int DaThuc::tinhGiaTri(int x)
{
    return coefficient * pow(x, exponent);    
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
    LinkedList DaoHam();
    void tinhGiaTri(int x);
    void Tong(LinkedList L1, LinkedList L2);
    void Tich(LinkedList L1, LinkedList L2);
    void display();
};

void LinkedList::display()
{
    Node* pTemp = _pHead;
    bool flag = true;
    while(pTemp != nullptr)
    {
        if(!flag && pTemp->_data.coefficient > 0) 
        {
            cout << '+';
        }
        pTemp->display();
        flag = false;
        pTemp = pTemp->_pNext;

    }
    cout << '\n';
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
        Temp->_data.coefficient += data.coefficient;
        if(Temp->_data.coefficient == 0)
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

LinkedList LinkedList::DaoHam()
{
    LinkedList res;
    Node* pTemp = _pHead;
    while(pTemp != nullptr)
    {
        DaThuc ans = pTemp->_data.DaoHam();
        if(ans.coefficient != 0)
        {
            res.add(ans);
        }
        pTemp = pTemp->_pNext;
    }
    return res;
}

void LinkedList::tinhGiaTri(int x)
{
    int ans = 0;
    Node* pTemp = _pHead;
    while(pTemp != nullptr)
    {
        ans += pTemp->_data.tinhGiaTri(x);
        pTemp = pTemp->_pNext;
    }
    cout << ans << '\n';
}

void LinkedList::Tong(LinkedList L1, LinkedList L2)
{
    Node* pTemp = L1._pHead;
    Node* pTemp2 = L2._pHead;

    while (pTemp != nullptr || pTemp2 != nullptr)
    {
       if(pTemp == nullptr)
       {
           add(pTemp2->_data);
           pTemp2 = pTemp2->_pNext;
       }
       else if(pTemp2 == nullptr)
       {
           add(pTemp->_data);
           pTemp = pTemp->_pNext;
       }
       else if(pTemp->_data.exponent > pTemp2->_data.exponent)
       {
           add(pTemp->_data);
           pTemp = pTemp->_pNext;
       }
       else if(pTemp->_data.exponent < pTemp2->_data.exponent)
       {
           add(pTemp2->_data);
           pTemp2 = pTemp2->_pNext;
       }
       else
       {
          DaThuc kq;
          kq.coefficient = pTemp->_data.coefficient + pTemp2->_data.coefficient;
          kq.exponent = pTemp->_data.exponent;
          if(kq.coefficient != 0)
          {
              this->add(kq);
          }
          pTemp = pTemp->_pNext;
          pTemp2 = pTemp2->_pNext;
       }
    }
}

void LinkedList::Tich(LinkedList L1, LinkedList L2)
{
    Node* p1 = L1._pHead;
    while(p1 != nullptr)
    {
        Node* p2 = L2._pHead;
        while(p2 != nullptr)
        {
            DaThuc ans;
            ans.coefficient = p1->_data.coefficient * p2->_data.coefficient;
            ans.exponent = p1->_data.exponent * p2->_data.exponent;
            this->add(ans);
            p2 = p2->_pNext;
        }
        p1 = p1->_pNext;
    }
}

int main()
{
    //a
    DaThuc a, a1;
    LinkedList L1, L2;
    while(cin >> a)
    {
        L1.add(a);
        if(cin.peek() == '\n')
            break;
    }
    while(cin >> a1)
    {
        L2.add(a1);
        if(cin.peek() == '\n')
            break;
    }
    //b
    L1.display();
    L2.display();
    //c
    LinkedList kq = L1.DaoHam();
    kq.display();
    L2.DaoHam();
    LinkedList kq2 = L2.DaoHam();
    kq2.display();
    //d
    int x;
    cin >> x;
    L1.tinhGiaTri(x);
    L2.tinhGiaTri(x);
    //e
    LinkedList L3;
    L3.Tong(L1, L2);
    L3.display();
    //
    LinkedList L4;
    L4.Tich(L1, L2);
    L4.display();
}