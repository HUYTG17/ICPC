#include <bits/stdc++.h>

using namespace std;

class MHoc
{
private:
    string Ma;
    string Ten;
    int Tinchi;
    float Diem;
    //int Somon;
public:
    void setMa(string k) { Ma = k;}
    string getMa() { return Ma; }
    void setTen(string k) { Ten = k; }
    string getTen() { return Ten; }
    void setTinchi(int k) { Tinchi = k; }
    int getTinchi() { return Tinchi; }
    void setDiem(float k) { Diem = k; }
    float getDiem() { return Diem; }
    //void setSomon(int k) { Somon = k; }
    //int getSomon() { return Somon; }
    friend istream& operator >> (istream& is, MHoc& m)
    {
        //is >> m.Somon;
        is >> m.Ma;
        is.ignore();
        getline(is, m.Ten);
        is >> m.Tinchi;
        is >> m.Diem;
        return is;
    }
    friend ostream& operator << (ostream& os, MHoc m)
    {
        //os << "So mon: " << m.Somon << '\n';
        os << "Ma: " << m.Ma << '\n';
        os << "Ten: " << m.Ten << '\n';
        os << "Tin chi: " << m.Tinchi << '\n';
        os << "Diem: " << m.Diem << '\n';
        return os;
    }
    float getScore() 
    {
        return Diem;
    }
};

class SVien
{
private:
    string Masv;
    string Hoten;
    string Ngaysinh;
    MHoc a[100];
    int n;
public:
    void setMasv(string k) { Masv = k; }
    string getMasv() { return Masv; }
    void setHoten(string k) { Hoten = k; }
    string getHoten() { return Hoten; }
    void setNgaysinh(string k) { Ngaysinh = k; }
    string getNgaysinh() { return Ngaysinh; }
    friend istream& operator >> (istream& is, SVien& sv)
    {
        is >> sv.Masv;
        is.ignore();
        getline(is, sv.Hoten);
        is >> sv.Ngaysinh;
        is >> sv.n;
        for(int i = 0; i < sv.n; i++)
        {
            is >> sv.a[i];
        }
        return is;
    }
    friend ostream& operator << (ostream& os, SVien sv)
    {
        os << "Ma sinh vien: " << sv.Masv << '\n';
        os << "Ho ten: " << sv.Hoten << '\n';
        os << "Ngay sinh: " << sv.Ngaysinh << '\n';
        os << "So mon hoc: " << sv.n << '\n';
        for(int i = 0; i < sv.n; i++)
        {
            os << "Mon hoc " << i + 1 << ":\n" << sv.a[i];
        }
        return os;
    }
    float Dtb() 
    {
        float dtb = 0;
        for(int i = 0; i < n; i++)
        {
            dtb += a[i].getScore();
        }
        return dtb / n;
    }
    //f
    bool HB()
    {
        for(int i = 0; i < n; i++)
        {
            if(a[i].getScore() < 5) return false;
        }
        return Dtb() >= 7;
    }
    //g
    int Ns()
    {
        int pos = Ngaysinh.find('/');
        string tmp = Ngaysinh.substr(pos + 1);
        return stoi(tmp.substr(tmp.find('/') + 1));
    }
};
//b
void linearSearch(SVien a[], int n, string x, string y)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i].getMasv() == x)
            a[i].setHoten(y);
    }
}
//c
void insertionSort(SVien a[], int n) 
{
    SVien x;
    int pos;
    for(int i = 1; i < n; i++)
    {
        x = a[i];
        for(pos = i; (pos > 0) && a[pos - 1].getHoten() < x.getHoten(); pos--)
            a[pos] = a[pos - 1];
        a[pos] = x;
    }
}
//d
void binarySearch(SVien a[], int& n, string x)
{
    sort(a, a + n, [](SVien a, SVien b)
    {
        return a.getHoten() < b.getHoten();
    });
    int l = 0, r = n - 1;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(a[mid].getHoten() == x) 
        {
            for(int i = mid; i < n - 1; i++)
            {
                a[i] = a[i + 1];
            }
            n--;
        }
        else if(a[mid].getHoten() < x)
        {
            l = mid + 1;
        }
        else 
        {
            r = mid - 1;
        }
    }
}
//e
void selectionSort(SVien a[], int n)
{
    int min;
    for(int i = 0; i < n - 1; i++)
    {
        min = i;
        for(int j = i + 1; j < n; j++)
            if(a[min].Dtb() > a[j].Dtb())
                min = j;
        if(min != i)
            swap(a[min], a[i]);
    }
}
//g
void quickSort(SVien a[], int left, int right)
{
    if(left >= right) return;
    SVien pivot = a[(left + right) / 2];
    int i = left, j = right;
    while(i < j)
    {
        while(a[i].Ns() < pivot.Ns()) i++;
        while(a[j].Ns() > pivot.Ns()) j--;
        if(i <= j)
        {
            swap(a[i], a[j]);
            i++; 
            j--;
        }
    }
    quickSort(a, left, j);
    quickSort(a, i, right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; 
    cin >> n;
    SVien a[100];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }// b va d b thi nhap them x nx
    string x, y;
    cin >> x;
    cin.ignore();
    getline(cin, y);
    // for(int i = 0; i < n; i++)
    // {
    //     if(a[i].getMasv() == x)
    //         a[i].setHoten(y);
    // }
    linearSearch(a, n, x, y);
    for(int i = 0; i < n; i++)
    {
        cout << a[i].getHoten() << '\n';
    }
    //insertionSort(a, n);
    //binarySearch(a, n, y);
    //selectionSort(a, n);
    //f
    // for(int i = 0; i < n; i++)
    // {
    //     if(a[i].HB())
    //     {
    //         cout << a[i].getHoten() << ' ' << a[i].Dtb() << '\n';
    //     //cout << a[i] << '\n';
    //     }
    // }
    // quickSort(a, 0, n - 1);
    // for(int i = 0; i < n; i++)
    // {
    //     cout << a[i].getHoten() << ' ' << a[i].Ns() << '\n';
    // }
    return 0;
}