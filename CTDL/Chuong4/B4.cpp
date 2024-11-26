#include <bits/stdc++.h>

using namespace std;

template<class DataType>
class Stack;
template<class DataType>
class Node
{
    friend class Stack<DataType>;
private:
    DataType _data;
    Node* _pNext;
public:
    Node(DataType data) : _data(data), _pNext(nullptr) {}
};

template<class DataType>
class Stack
{
private:
    Node<DataType>* _pTop;
public:
    Stack() : _pTop(nullptr) {}
    ~Stack();
    
    bool isEmpty();
    void push(DataType data);
    DataType pop();
};

template<class DataType>
bool Stack<DataType>::isEmpty()
{
    return (_pTop == nullptr);
}

template<class DataType>
void Stack<DataType>::push(DataType data)
{
    Node<DataType>* pAdd = new Node<DataType>(data);
    pAdd->_pNext = _pTop;
    _pTop = pAdd;
}

template<class DataType>
DataType Stack<DataType>::pop()
{
    if(isEmpty())
    {
        cout << "Stack rong!!!";
    }
    else
    {
        Node<DataType>* pTemp = _pTop;
        DataType temp = pTemp->_data;
        _pTop = pTemp->_pNext;
        delete pTemp;
        return temp;
    }
}

void quickSort(int a[], int left, int right)
{
    Stack<pair<int, int>> st;
    st.push({left, right});
    while(!st.isEmpty())
    {
        pair<int, int> p = st.pop();
        int l = p.first, r = p.second;
        int x = a[(l + r) / 2];
        int i = l, j = r;
        while(i < j)
        {
            while(a[i] < x) i++;
            while(a[j] > x) j--;
            if(i <= j)
            {
                swap(a[i], a[j]);
                i++; j--;
            }
        }
        if(l < j) st.push({l, j});
        if(i < r) st.push({i, r});
    }
}
    
template<class DataType>
Stack<DataType>::~Stack()
{
    while(_pTop != nullptr)
    {
        Node<DataType>* pTemp = _pTop;
        _pTop = _pTop->_pNext;
        delete pTemp;
    }
}

int main()
{
    Stack<pair<int, int>> st;
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
    for(int i = 0; i < n; ++i)
    {
        cout << a[i] << ' ';
    }
}

/*
input
10
7 2 9 4 6 3 8 1 10 5
output
1 2 3 4 5 6 7 8 9 10
*/