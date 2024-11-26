#define MAX_SIZE 10

#include <iostream>

using namespace std;

class ArrayList;
class SACH
{
    friend class ArrayList;
private:
    string Ma;
    string Ten;
    int SoTo;
public:
    SACH(string _Ma = "", string _Ten = "", int _SoTo = 0);
    friend istream& operator >> (istream& is, SACH& sach);
};

SACH::SACH(string _Ma, string _Ten, int _SoTo)
{
    Ma = _Ma;
    Ten = _Ten;
    SoTo = _SoTo;
}

istream& operator >> (istream& is, SACH& sach)
{
    is.ignore();
    is >> sach.Ma;
    is >> sach.Ten;
    is >> sach.SoTo;
    return is;
}
class ArrayList
{
private:
    SACH* _items;
    int _iCapacity;
    int _iSize;
public:
    ArrayList();
    ArrayList(int maxSize);
    ~ArrayList();
    
    bool isEmpty();
    bool isFull();
    void add(SACH data);
    int Search(string ma);
};

ArrayList::ArrayList()
{
    _iCapacity = MAX_SIZE;
    _items = new SACH[_iCapacity];
    _iSize = 0;
}

ArrayList::ArrayList(int maxSize)
{
    _iCapacity = maxSize > 0 ? maxSize : MAX_SIZE;
    _items = new SACH[_iCapacity];
    _iSize = 0;
}

ArrayList::~ArrayList()
{
    delete[] _items;
}

bool ArrayList::isEmpty()
{
    if(_iSize == 0)
        return true;
    return false;
}

bool ArrayList::isFull()
{
    if(_iSize == _iCapacity)
        return true;
    return false;
}


void ArrayList::add(SACH data)
{
    if(!isFull())
    {
       _items[_iSize] = data;
       _iSize++;
    }
    else
        cout << "List day ! Khong the them phan tu moi!\n";
}

int ArrayList::Search(string ma)
{
    for(int i = 0; i < _iSize; ++i)
    {
        if(_items[i].Ma == ma)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    string ma; cin >> ma;
    int n; cin >> n;
    ArrayList arl(n + 1);
    SACH a;
    for(int i = 0; i < n; ++i)
    {
        cin >> a;
        arl.add(a);
    }
    cout << arl.Search(ma);
}