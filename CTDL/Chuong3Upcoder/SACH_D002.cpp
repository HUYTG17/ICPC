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
    void interchangeSort();
    void display();
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
    return _iSize == 0;
}

bool ArrayList::isFull()
{
    return _iSize == _iCapacity;
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

void ArrayList::interchangeSort()
{
    for(int i = 0; i < _iSize - 1; ++i)
    {
        for(int j = i + 1; j < _iSize; ++j)
        {
            if(_items[i].SoTo > _items[j].SoTo)
                swap(_items[i], _items[j]);
        }
    }
}

void ArrayList::display()
{
    for(int i = 0; i < _iSize; ++i)
    {
         _items[i].display();
         cout << '\n';
    }
}

int main()
{
    int n;
    cin >> n;
    ArrayList *arl = new ArrayList[n + 1];
    SACH a;
    for(int i = 0; i < n; ++i)
    {
        cin >> a;
        arl->add(a);
    }
    arl->interchangeSort();
    arl->display();
}