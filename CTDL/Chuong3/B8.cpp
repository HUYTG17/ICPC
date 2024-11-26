#include <bits/stdc++.h>

using namespace std;

class Video
{
private:
    string Ten;
    string Loai;
    string DaoDien;
    string NamChinh;
    string NuChinh;
    int NamSanXuat;
public:
    void setTen(string Ten)
    {
        this->Ten = Ten;
    }
    void setLoai(string Loai)
    {
        this->Loai = Loai;
    }
    void setDaoDien(string DaoDien)
    {
        this->DaoDien = DaoDien;
    }
    void setNamChinh(string NamChinh)
    {
        this->NamChinh = NamChinh;
    }
    void setNuChinh(string NuChinh)
    {
        this->NuChinh = NuChinh;
    }
    void setNamSanXuat(int NamSanXuat)
    {
        this->NamSanXuat = NamSanXuat;
    }
    string getTen()
    {
        return Ten;
    }
    string getLoai()
    {
        return Loai;
    }
    string getDaoDien()
    {
        return DaoDien;
    }
    string getNamChinh()
    {
        return NamChinh;
    }
    string getNuChinh()
    {
        return NuChinh;
    }
    int getNamSanXuat()
    {
        return NamSanXuat;
    }
    friend istream& operator >> (istream& is, Video &vd)
    {
        string str;
        getline(is, str);
        vd.setTen(str.substr(0, str.find('#')));
        str = str.substr(str.find('#') + 1);
        vd.setLoai(str.substr(0, str.find('#')));
        str = str.substr(str.find('#') + 1);
        vd.setDaoDien(str.substr(0, str.find('#')));
        str = str.substr(str.find('#') + 1);
        vd.setNamChinh(str.substr(0, str.find('#')));
        str = str.substr(str.find('#') + 1);
        vd.setNuChinh(str.substr(0, str.find('#')));
        str = str.substr(str.find('#') + 1);
        vd.setNamSanXuat(stoi(str));
        return is;
    }
    friend ostream& operator << (ostream& os, Video vd)
    {
        os << "Ten Phim: " << vd.getTen() << '\n';
        os << "The Loai: " << vd.getLoai() << '\n';
        os << "Ten Dao Dien: " << vd.getDaoDien() << '\n';
        os << "Ten Nam Chinh: " << vd.getNamChinh() << '\n';
        os << "Ten Nu Chinh: " << vd.getNuChinh() << '\n';
        os << "Nam San Xuat: " << vd.getNamSanXuat() << '\n';
        return os;
    }
};

class LinkedList;
class Node
{
    friend class LinkedList;
private:
    Video _data;
    Node* _pNext;
public:
    Node(Video data) : _data(data), _pNext(nullptr) {}
};

class LinkedList
{
private:
    Node* _pHead;
    Node* _pTail;
public:
    LinkedList() : _pHead(nullptr), _pTail(nullptr) {}
    
    void addTail(Video data)
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
    }

    void display()
    {
        Node* p = _pHead;
        while(p != nullptr)
        {
            cout << p->_data;
            p = p->_pNext;
        }
    }
    
    void Update(string X, string TheLoaiMoi)
    {
        Node* p = _pHead;
        while(p != nullptr)
        {
            if(p->_data.getTen() == X)
            {
                p->_data.setLoai(TheLoaiMoi);
                break;
            }
            p = p->_pNext;
        }
    }
    
    void solveTaskD(string name)
    {
        string fileName = name + ".txt";
        ofstream out(fileName);
        if(out.is_open())
        {
            Node* p = _pHead;
            while(p != nullptr)
            {
                if(p->_data.getNamChinh() == name)
                {
                    out << p->_data << '\n';
                }
                p = p->_pNext;
            }
        }
    }
    void solveTaskE()
    {
        unordered_map<string, vector<Video>> v;
        Node* p = _pHead;
        while(p != nullptr)
        {
            v[p->_data.getDaoDien()].push_back(p->_data);
            p = p->_pNext;
        }
        for(auto it : v)
        {
            ofstream out(it.first + ".txt");
            if(out.is_open())
            {
                out << it.second.size() << '\n';
                for(auto it2 : it.second)
                {
                    out << it2 << '\n';
                }
            }
        }
    }

    void interchangeSort()
    {
        for(Node* i = _pHead; i->_pNext != nullptr; i = i->_pNext)
        {
            for(Node* j = i->_pNext; j != nullptr; j = j->_pNext)
            {
                if(i->_data.getNamSanXuat() < j->_data.getNamSanXuat())
                {
                    swap(i->_data, j->_data);
                }
            }
        }
    }

    void solveTaskF()
    {
        ofstream out("PhimMoi.txt");
        if(out.is_open())
        {
            Node* p = _pHead;
            for(int i = 0; i < 3; ++i)
            {
                out << p->_data << '\n';
                p = p->_pNext;
            }
        }
    }
};

void solve()
{
    //a
    LinkedList lt1;
    ifstream in("Input.txt");
    if (!in.is_open()) {
        cerr << "Khong the mo file Input.txt" << endl;
        return;
    }
    int n;
    in >> n;
    in.ignore();
    while(n--)
    {
        Video vd;
        in >> vd;
        lt1.addTail(vd);
    }
    //b
    //string s;
    //getline(in, s);
    //lt1.Update(s, "tinh cam");
    //c
    //lt1.display();
    //d
    //string name;
    //getline(cin, name);
    //lt1.solveTaskD(name);
    //e
    //lt1.solveTaskE();
    //f
    lt1.interchangeSort();
    lt1.solveTaskF();
}

int main()
{
    solve();
    return 0;
}