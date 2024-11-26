#include <bits/stdc++.h>

using namespace std;

template<class DataType>
class LinkedList;
template<class DataType>
class Node
{
    friend LinkedList<DataType>;
private:
    DataType _data;
    Node* _pNext;
public:
    Node(DataType data);
    void display();
};

template<class DataType>
Node<DataType>::Node(DataType data)
{
    _data = data;
    _pNext = nullptr;
}

template<class DataType>
void Node<DataType>::display()
{
    cout << _data << '\n';
}

template<class DataType>
class LinkedList
{
private:
    Node<DataType>* _pHead;
    Node<DataType>* _pTail;
    int _iSize;
public:
    LinkedList();
    ~LinkedList();
    
    void addHead(DataType data);
    void addTail(DataType data);
    void addAfter(Node<DataType>* node, DataType data);
    
    Node<DataType>* search(DataType data);
    Node<DataType>* searchPre(Node<DataType>* node);
    
    void removeHead();
    void removeTail();
    void removeAfter(Node<DataType>* node);
    void remove(DataType data);
    
    void selectionSort();
    int getSize();
    void display();
    void clear();
};

template<class DataType>
LinkedList<DataType>::LinkedList()
{
    _pHead = nullptr;
    _pTail = nullptr;
    _iSize = 0;
}

template<class DataType>
LinkedList<DataType>::~LinkedList()
{
    clear();
}

template<class DataType>
void LinkedList<DataType>::display()
{
    Node<DataType>* pTemp = _pHead;
    while(pTemp != nullptr)
    {
        pTemp->display();
        pTemp = pTemp->_pNext;
    }
}

template<class DataType>
void LinkedList<DataType>::addHead(DataType data)
{
    Node<DataType>* pAdd = new Node<DataType>(data);
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

template<class DataType>
void LinkedList<DataType>::addTail(DataType data)
{
    Node<DataType>* pAdd = new Node<DataType>(data);
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

template<class DataType>
void LinkedList<DataType>::addAfter(Node<DataType>* node, DataType data)
{
    Node<DataType>* pAdd = new Node<DataType>(data);
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

template<class DataType>
Node<DataType>*LinkedList<DataType>::search(DataType data)
{
    Node<DataType>* p = _pHead;
    while((p != nullptr) && p->_data != data)
        p = p->_pNext;
    return p;
}

template<class DataType>
Node<DataType>*LinkedList<DataType>::searchPre(Node<DataType>* node)
{
    Node<DataType>* p = _pHead;
    if(p == node)
        return nullptr;
    while((p != nullptr) && (p->_pNext != node))
        p = p->_pNext;
    return p;
}

template<class DataType>
void LinkedList<DataType>::removeHead()
{
    if(_pHead != nullptr)
    {
        Node<DataType>* pTemp = _pHead;
        _pHead = _pHead->_pNext;
        delete pTemp;
        if(_pHead == nullptr)
            _pTail = nullptr;
        _iSize--;
    }
}

template<class DataType>
void LinkedList<DataType>::removeTail()
{
    if(_pTail == nullptr)
        return;
    Node<DataType>* pTemp = _pTail;
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

template<class DataType>
void LinkedList<DataType>::removeAfter(Node<DataType>* node)
{
    Node<DataType>* pTemp = _pHead;
    if(node != nullptr)
    {
        pTemp = node->_pNext;
        if(pTemp != nullptr)
        {
            if(pTemp == _pTail)
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

template<class DataType>
void LinkedList<DataType>::remove(DataType data)
{
    Node<DataType>* pWalker = _pHead, *pTemp = nullptr;
    while((pWalker != nullptr) && (pWalker->_data != data))
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

template<class DataType>
void LinkedList<DataType>::clear()
{
    while(_pHead != nullptr)
        removeHead();
}

template<class DataType>
void LinkedList<DataType>::selectionSort()
{
    Node<DataType>* min;
    for(Node<DataType>* i = _pHead; i->_pNext != nullptr; i = i->_pNext)
    {
        min = i;
        for(Node<DataType>* j = i->_pNext; j != nullptr; j = j->_pNext)
            if(min->_data > j->_data)
                min = j;
        if(min != i)
            swap(min->_data, i->_data);
    }
}

template<class DataType>
int LinkedList<DataType>::getSize()
{
    return _iSize;
}

int main()
{
    int type, n;
    cin >> type >> n;
    
    LinkedList<string> l1;
    LinkedList<int> l2;
    LinkedList<double> l3;
    LinkedList<char> l4;
    switch(type)
    {
        case 1: 
        {
            string s;
            for(int i = 0; i < n; ++i)
            {
                cin >> s;
                l1.addTail(s);
            }
            // for(int i = 0; i < n; ++i)
            // {
            //     cin >> s;
            //     l1.addHead(s);
            // }
            // string x;
            // cin >> x;
            // Node<string>* find = l1.search(x);
            // string y;
            // cin >> y;
            //l1.addAfter(find, y);
            // l1.removeHead();
            // l1.removeTail();
            // l1.remove();
            l1.selectionSort();
            cout << l1.getSize() << '\n';
            l1.display();
            break;
        }
        case 2:
        {
            int s1;
            for(int i = 0; i < n; ++i)
            {
                cin >> s1;
                l2.addTail(s1);
            }
            // for(int i = 0; i < n; ++i)
            // {
            //     cin >> s1;
            //     l2.addHead(s1);
            // }
            // int x;
            // cin >> x;
            // Node<int>* find = l2.search(x);
            // int y;
            // cin >> y;
            // l2.addAfter(find, y);
            // l2.removeHead();
            // l2.removeTail();
            // l2.remove();
            l2.selectionSort();
            cout << l2.getSize() << '\n';
            l2.display();
            break;
        }
        case 3:
        {
            double s1;
            for(int i = 0; i < n; ++i)
            {
                cin >> s1;
                l3.addTail(s1);
            }
            // for(int i = 0; i < n; ++i)
            // {
            //     cin >> s1;
            //     l3.addHead(s1);
            // }
            // double x;
            // cin >> x;
            // Node<double>* find = l3.search(x);
            // double y;
            // cin >> y;
            // l3.addAfter(find, y);
            // l3.removeHead();
            // l3.removeTail();
            // l3.remove();
            l3.selectionSort();
            cout << l3.getSize() << '\n';
            l3.display();
            break;
        }
        case 4:
        {
            char s1;
            for(int i = 0; i < n; ++i)
            {
                cin >> s1;
                l4.addTail(s1);
            }
            // for(int i = 0; i < n; ++i)
            // {
            //     cin >> s1;
            //     l4.addHead(s1);
            // }
            // char x;
            // cin >> x;
            // Node<char>* find = l4.search(x);
            // char y;
            // cin >> y;
            // l4.addAfter(find, y);
            // l4.removeHead();
            // l4.removeTail();
            // l4.remove();
            l4.selectionSort();
            cout << l4.getSize() << '\n';
            l4.display();
            break;
        }
        default:
        {
            cout << "Khong hop le!";
            break;
        }
    }
}