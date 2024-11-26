#define ll long long
#define TGH return 0
#define TG ios_base::sync_with_stdio(false)
#define H cin.tie(nullptr)

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ifile freopen("inp.txt", "r", stdin)
#define ofile freopen("out.txt", "w", stdout)

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

class Sach 
{
private:
    string MaSach;
    string TuaSach;
    int NamXuatBan;
    int Gia;
public:
    void setNamXuatBan(int k) { NamXuatBan = k; }
    int getNamXuatBan() { return NamXuatBan; }
    void setMaSach(string k) { MaSach = k; }
    string getMaSach() { return MaSach; }
    void setTuaSach(string k) { TuaSach = k; }
    string getTuaSach() { return TuaSach; }
    void setGia(int k) {Gia = k; } 
    int getGia() { return Gia; }
    friend istream& operator >> (istream& is, Sach& s)
    {
        is >> s.MaSach;
        is.ignore();
        getline(is, s.TuaSach);
        is >> s.NamXuatBan;
        is >> s.Gia;
        return is;
    }
    friend ostream& operator << (ostream& os, Sach s)
    {
        os << "Ma Sach: " << s.MaSach << '\n';
        os << "Tua Sach: " << s.TuaSach << '\n';
        os << "Nam xuat ban: " << s.NamXuatBan << '\n';
        os << "Gia: " << s.Gia << '\n';
        return os;
    }
};
//b
void LinearSearch(Sach a[], int n, string x, int y)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i].getTuaSach() == x)
            a[i].setGia(y);
    }
}
//c
void BinarySearch(Sach a[], int& n, string x)
{
    sort(a, a + n, [](Sach a, Sach b)
    {
        return a.getMaSach() < b.getMaSach();
    });
    int l = 0, r = n - 1;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(a[mid].getMaSach() == x)
        {
            for(int i = mid; i < n - 1; i++)
            {
                a[i] = a[i + 1];
            }
            n--;
            break;
        }
        else if(a[mid].getMaSach() < x) l = mid + 1;
        else r = mid - 1;
    }
}
//d
void SelectionSort(Sach a[], int n)
{
    int min;
    for(int i = 0; i < n - 1; i++)
    {
        min = i;
        for(int j = i + 1; j < n; j++)
            if(a[min].getMaSach() > a[j].getMaSach())
                min = j;
        if(min != i)
            swap(a[min], a[i]);
    }
}
//e
void InsertionSort(Sach a[], int n)
{
    int pos;
    Sach x;
    for(int i = 1; i < n; i++)
    {
        x = a[i];
        for(pos = i; (pos > 0) && (a[pos - 1].getNamXuatBan() < x.getNamXuatBan()); pos--)
            a[pos] = a[pos - 1];
        a[pos] = x;
    }
}
//f
void BubbleSort(Sach a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = n - 1; j > i; j--)
        {
            if(a[j].getTuaSach() < a[j - 1].getTuaSach())
                swap(a[j], a[j - 1]);
        }
    }
}
//g
void QuickSort(Sach a[], int left, int right)
{
    if(left >= right) return;
    Sach pivot = a[(left + right) / 2];
    int i = left, j = right;
    while(i < j)
    {
        while(a[i].getGia() > pivot.getGia()) i++;
        while(a[j].getGia() < pivot.getGia()) j--;
        if(i <= j)
        {
            swap(a[i], a[j]);
            i++; j--;
        }
    }
    QuickSort(a, left, j);
    QuickSort(a, i, right);
}

int main() {
    TG; H;

    Sach a[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // b
    // cin.ignore();
    // string x;
    // getline(cin, x);
    // int y;
    // cin >> y;
    // LinearSearch(a, n, x, y);
    // for(int i = 0; i < n; i++)
    // {
    //     cout << a[i].getGia() << '\n';
    // }
    // c
    // cin.ignore();
    // string x;
    // getline(cin, x);
    // BinarySearch(a, n, x);
    // for(int i = 0; i < n; i++)
    // {
    //     cout << a[i].getMaSach() << '\n';
    // }
    //d
    SelectionSort(a, n);
    for(int i = 0; i < n; i++)
    {
        cout << a[i].getMaSach() << '\n';
    }
    //e
    // InsertionSort(a, n);
    // for(int i = 0; i < n; i++)
    // {
    //     cout << a[i].getNamXuatBan() << '\n';
    // }
    //f
    // BubbleSort(a, n);
    // for(int i = 0; i < n; i++)
    // {
    //     cout << a[i].getTuaSach() << '\n';
    // }
    // QuickSort(a, 0 , n - 1);
    // for(int i = 0; i < n; i++)
    // {
    //     cout << a[i].getGia() << '\n';
    // }
    TGH;
}