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
    void display()
    {
        cout << _data << ' ';
    }
};

template<class DataType>
class Stack
{
private:
    Node<DataType>* _pTop;
    int _iSize;
public:
    Stack() : _pTop(nullptr), _iSize(0) {}
    ~Stack() 
    {
        clear();
    }
    bool isEmpty()
    {
        return (_pTop == nullptr);
    }
    void push(DataType data)
    {
        Node<DataType>* pAdd = new Node<DataType>(data);
        pAdd->_pNext = _pTop;
        _pTop = pAdd;
        _iSize++;
        if(isEmpty())
        {
            cout << "Stack rong!!!";
            exit(0);
        }
    }
    DataType pop()
    {
        if(isEmpty())
        {
            cout << "Stack rong!!!";
            exit(0);
        }
        Node<DataType>* pTemp = _pTop;
        DataType temp = pTemp->_data;
        _pTop = pTemp->_pNext;
        delete pTemp;
        _iSize--;
        return temp;
    }
    DataType peek()
    {
        if(isEmpty())
        {
            cout << "Stack rong!!!";
            exit(0);
        }
        return _pTop->_data;
    }
    void display()
    {
        if(isEmpty())
        {
            cout << "Stack rong!!!";
            exit(0);
        }
        Node<DataType>* pTemp = _pTop;
        while(pTemp != nullptr)
        {
            pTemp->display();
            pTemp = pTemp->_pNext;
        }
    }
    int getSize()
    {
        return _iSize;
    }
    void clear()
    {
        while(_pTop != nullptr)
        {
            Node<DataType>* pTemp = _pTop;
            _pTop = _pTop->_pNext;
            delete pTemp;
        }
        _iSize = 0;
    }
};

template<class DataType>
void display(Stack<DataType>& stack)
{
    int iOption = 0;
    do
    {
        system("cls");
        cout << "Cac thao tac tren Stack:\n";
        cout << "1. Kiem tra Stack rong.\n";
        cout << "2. Them phan tu vao dinh Stack.\n";
        cout << "3. Lay phan tu o dinh Stack.\n";
        cout << "4. Xem gia tri phan tu o dinh Stack.\n";
        cout << "5. Hien thi Stack.\n";
        cout << "6. Huy bo Stack.\n";
        cout << "0. Ket thuc chuong trinh.\n";
        cout << "Ban chon thao tac nao?\n";
        cin >> iOption;
        switch(iOption)
        {
            case 1: 
            {
                if(stack.isEmpty())
                    cout << "Stack rong!!!\n";
                else
                    cout << "Stack khac rong!!\n!";
                system("pause");
                break;
            }
            case 2:
            {
                DataType iData;
                cout << "Nhap gia tri can them: ";
                cin >> iData;
                stack.push(iData);
                cout << "Gia tri " << iData << " da duoc them vao Stack.\n";
                system("pause");
                break;
            }
            case 3:
            {
                if(stack.isEmpty())
                    cout << "Stack rong!!!\n";
                else
                {
                    DataType iTop = stack.pop();
                    cout << "Phan tu o dinh Stack duoc lay ra: " << iTop << '\n';
                }
                system("pause");
                break;
            }
            case 4:
            {
                if(stack.isEmpty())
                    cout << "Stack rong!!!\n";
                else
                {
                    DataType iTop = stack.peek();
                    cout << "Gia tri cua phan tu o dinh Stack: " << iTop << '\n';
                }
                system("pause");
                break;
            }
            case 5:
            {
                stack.display();
                system("pause");
                break;
            }
            case 6:
            {
                stack.clear();
                cout << "Da huy bo Stack\n";
                system("pause");
                break;
            }
            default:
                break;
        }
    } while(iOption != 0);
}
int main()
{
    Stack<int> stack;
    Stack<float> stack2;
    Stack<char> stack3;
    Stack<string> stack4;

    int type;
    cout << "Ban nhap du lieu nao:\n";
    cout << "0 la du lieu int\n";
    cout << "1 la du lieu float\n";
    cout << "2 la du lieu char\n";
    cout << "3 la du lieu string\n";
    cout << "Moi ban nhap so tu 0 den 3: ";
    cin >> type;
    switch(type)
    {
        case 0: display(stack); break;
        case 1: display(stack2); break;
        case 2: display(stack3);break;
        case 3: display(stack4); break;
        default: cout << "Lua chon khong hop le\n"; break;
    }
    return 0;
}