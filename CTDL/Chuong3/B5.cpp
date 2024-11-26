#include <bits/stdc++.h>

using namespace std;

class Node;
class LinkedList;
class SinhVien
{
    friend class Node;
    friend class LinkedList;
private:
    string Ma;
    string HoTen;
    string Lop;
    string NgaySinh;
    double Dtb;
public:
    SinhVien() : Ma("ma"), HoTen("ht"), Lop("l"), NgaySinh("ns"), Dtb(0) {}
    
    friend istream& operator >> (istream& is, SinhVien &sv);
    void display();
};

istream& operator >> (istream& is, SinhVien &sv)
{
    is.ignore();
    getline(is, sv.Ma);
    getline(is, sv.HoTen);
    getline(is, sv.Lop);
    getline(is, sv.NgaySinh);
    cin >> sv.Dtb;
    return is;
}

void SinhVien::display()
{
    cout << "Ma: " << Ma << '\n';
    cout << "Ho va ten: " << HoTen << '\n';
    cout << "Lop: " << Lop << '\n';
    cout << "Ngay sinh: " << NgaySinh << '\n';
    cout << "Diem trung binh: " << Dtb << '\n';
}

class Node
{
    friend class LinkedList;
private:
    SinhVien _data;
    Node* _pNext;
public:
    Node(SinhVien data) : _data(data), _pNext(nullptr) {} 
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
    int _iSize;
public:
    LinkedList() : _pHead(nullptr), _pTail(nullptr), _iSize(0) {}
    void display();
    
    void addTail(SinhVien data);
    void linearSearch(string a);
    void selectionSort();
    void binarySearch(string a);
    void DtbTrenNam();
    void remove(string a);
    void CapNhatDiem(string a, double diem);
};

void LinkedList::display()
{
    Node* pTemp = _pHead;
    while(pTemp != nullptr)
    {
        pTemp->display();
        pTemp = pTemp->_pNext;
    }
}

void LinkedList::addTail(SinhVien data)
{
    Node* pAdd = new Node(data);
    if(_pHead== nullptr)
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

void LinkedList::DtbTrenNam()
{
    Node* pTemp = _pHead;
    while(pTemp != nullptr)
    {
        if(pTemp->_data.Dtb >= 5)
        {
            pTemp->display();
        }
        pTemp = pTemp->_pNext;
    }
}

void LinkedList::linearSearch(string a)
{
    for(Node* i = _pHead; i != nullptr; i = i->_pNext)
    {
        if(i->_data.Ma == a)
        {
            i->display();
        }
    }
}

void LinkedList::selectionSort()
{   
    Node* min;
    for(Node* i = _pHead; i->_pNext != nullptr; i = i->_pNext)
    {
        min = i;
        for(Node* j = i->_pNext; j != nullptr; j = j->_pNext)
            if(j->_data.Ma < min->_data.Ma)
                min = j;
        if(min != i)
            swap(min->_data, i->_data);
    }
}

void LinkedList::binarySearch(string a)
{
    this->selectionSort();
    int l = 0, r = _iSize - 1;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        Node* midNode = _pHead;
        for(int i = 0; i < mid; ++i)
        {
            midNode = midNode->_pNext;
        }
        if(midNode->_data.Ma == a)
        {
            midNode->display();
            break;
        }
        else if(midNode->_data.Ma < a)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
}


void LinkedList::remove(string a)
{
    Node* pWalker = _pHead, *pTemp = nullptr;
    while((pWalker != nullptr) && (pWalker->_data.Ma != a))
    {
        pTemp = pWalker;
        pWalker = pWalker->_pNext;
    }
    if(pWalker == nullptr) return;
    if(pWalker == _pHead)
    {
        _pHead = _pHead->_pNext;
        if(_pHead == nullptr)
        {
            _pTail = nullptr;
        }
    }
    else
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
    }
    delete pWalker;
    _iSize--;
}

void LinkedList::CapNhatDiem(string a, double diem)
{
    Node* pTemp = _pHead;
    while(pTemp != nullptr)
    {
        if(pTemp->_data.Ma == a)
        {
            pTemp->_data.Dtb = diem;
            cout << pTemp->_data.HoTen << ' ' << pTemp->_data.Dtb;
        }
        pTemp = pTemp->_pNext;
    }
}

int main()
{
    LinkedList l1;
    int n;
    cin >> n;
    SinhVien sv;
    //a
    for(int i = 0; i < n; ++i)
    {
        cin >> sv;
        l1.addTail(sv);
    }
    //b
    //l1.display();
    /*
    input
    2
    4901104058
    Tran Gia Huy
    CNTTD
    17/11/2005
    9.9
    4901104009
    Pham Gia Bao
    CNTT D
    14/11/2005
    9.8
    output
    Ma: 4901104058
    Ho va ten: Tran Gia Huy
    Lop: CNTTD
    Ngay sinh: 17/11/2005
    Diem trung binh: 9.9
    Ma: 4901104009
    Ho va ten: Pham Gia Bao
    Lop: CNTT D
    Ngay sinh: 14/11/2005
    Diem trung binh: 9.8
    */
    //c
    //l1.DtbTrenNam();
    /*
    input
    4
    4901104058
    Tran Gia Huy
    CNTTD
    17/11/2005
    9.9
    4901104009
    Pham Gia Bao
    CNTT D
    14/11/2005
    9.8
    4901104074
    N T K
    CNTTD
    4/5/2005
    5.0
    4901104081
    V C L
    CNTTD
    5/9/2005
    4.9
    output
    Ma: 4901104058
    Ho va ten: Tran Gia Huy
    Lop: CNTTD
    Ngay sinh: 17/11/2005
    Diem trung binh: 9.9
    Ma: 4901104009
    Ho va ten: Pham Gia Bao
    Lop: CNTT D
    Ngay sinh: 14/11/2005
    Diem trung binh: 9.8
    Ma: 4901104074
    Ho va ten: N T K
    Lop: CNTTD
    Ngay sinh: 4/5/2005
    Diem trung binh: 5
    */
    //d
    /*
    string a;
    cin >> a;
    l1.linearSearch(a);
    */
    /*
    input
    4
    4901104058
    Tran Gia Huy
    CNTTD
    17/11/2005
    9.9
    4901104009
    Pham Gia Bao
    CNTT D
    14/11/2005
    9.8
    4901104074
    N T K
    CNTTD
    4/5/2005
    5.0
    4901104081
    V C L
    CNTTD
    5/9/2005
    4.9
    4901104058
    output
    Ma: 4901104058
    Ho va ten: Tran Gia Huy
    Lop: CNTTD
    Ngay sinh: 17/11/2005
    Diem trung binh: 9.9
    */
    //e
    /*
    l1.selectionSort();
    l1.display();
    */
    /*
    4
    4901104058
    Tran Gia Huy
    CNTTD
    17/11/2005
    9.9
    4801104009
    Pham Gia Bao
    CNTT D
    14/11/2005
    9.8
    4701104074
    N T K
    CNTTD
    4/5/2005
    5.0
    4601104081
    V C L
    CNTTD
    5/9/2005
    4.9
    output:
    Ma: 4601104081
    Ho va ten: Tran Gia Huy
    Lop: CNTTD
    Ngay sinh: 17/11/2005
    Diem trung binh: 9.9
    Ma: 4701104074
    Ho va ten: Pham Gia Bao
    Lop: CNTT D
    Ngay sinh: 14/11/2005
    Diem trung binh: 9.8
    Ma: 4801104009
    Ho va ten: N T K
    Lop: CNTTD
    Ngay sinh: 4/5/2005
    Diem trung binh: 5
    Ma: 4901104058
    Ho va ten: V C L
    Lop: CNTTD
    Ngay sinh: 5/9/2005
    Diem trung binh: 4.9
    */
    //f
    /*
    string a;
    cin >> a;
    l1.binarySearch(a);
    */
    /*
    4
    4901104058
    Tran Gia Huy
    CNTTD
    17/11/2005
    9.9
    4801104009
    Pham Gia Bao
    CNTT D
    14/11/2005
    9.8
    4701104074
    N T K
    CNTTD
    4/5/2005
    5.0
    4601104081
    V C L
    CNTTD
    5/9/2005
    4.9
    4901104058
    output
    Ma: 4901104058
    Ho va ten: Tran Gia Huy
    Lop: CNTTD
    Ngay sinh: 17/11/2005
    Diem trung binh: 9.9
    */
    //g
    /*
    string a;
    cin >> a;
    l1.remove(a);
    l1.display();
    */
    /*
    4
    4901104058
    Tran Gia Huy
    CNTTD
    17/11/2005
    9.9
    4801104009
    Pham Gia Bao
    CNTT D
    14/11/2005
    9.8
    4701104074
    N T K
    CNTTD
    4/5/2005
    5.0
    4601104081
    V C L
    CNTTD
    5/9/2005
    4.9
    4901104058
    (xoa dau, giua, cuoi cho 1 ham remove duoc luon)
    output
    Ma: 4801104009
    Ho va ten: Pham Gia Bao
    Lop: CNTT D
    Ngay sinh: 14/11/2005
    Diem trung binh: 9.8
    Ma: 4701104074
    Ho va ten: N T K
    Lop: CNTTD
    Ngay sinh: 4/5/2005
    Diem trung binh: 5
    Ma: 4601104081
    Ho va ten: V C L
    Lop: CNTTD
    Ngay sinh: 5/9/2005
    Diem trung binh: 4.9
    */
    //h
    string x;
    cin >> x;
    double diem;
    cin >> diem;
    l1.CapNhatDiem(x, diem);
    //l1.display();
    /*
    input
    4
    4901104058
    Tran Gia Huy
    CNTTD
    17/11/2005
    9.9
    4801104009
    Pham Gia Bao
    CNTT D
    14/11/2005
    9.8
    4701104074
    N T K
    CNTTD
    4/5/2005
    5.0
    4601104081
    V C L
    CNTTD
    5/9/2005
    4.9
    4901104058
    10.01
    output
    Ma: 4901104058
    Ho va ten: Tran Gia Huy
    Lop: CNTTD
    Ngay sinh: 17/11/2005
    Diem trung binh: 10.01
    Ma: 4801104009
    Ho va ten: Pham Gia Bao
    Lop: CNTT D
    Ngay sinh: 14/11/2005
    Diem trung binh: 9.8
    Ma: 4701104074
    Ho va ten: N T K
    Lop: CNTTD
    Ngay sinh: 4/5/2005
    Diem trung binh: 5
    Ma: 4601104081
    Ho va ten: V C L
    Lop: CNTTD
    Ngay sinh: 5/9/2005
    Diem trung binh: 4.9
    */
    return 0;
}