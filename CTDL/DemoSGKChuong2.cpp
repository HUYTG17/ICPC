#include <iostream>
using namespace std;
class Key {
    public:
        int getdata() const { return data; }
        Key(int _data = 0) {
            data = _data;
        }
        friend istream& operator >> (istream& is, Key &k) {
            is >> k.data;
            return is;
        }
        friend ostream& operator << (ostream& os, const Key &k) {
            os << "Du lieu la: " << k.data;
            return os;
        }
        bool operator > (const Key &k) const {
            return data > k.data;
        }
    private:
        int data;
};
class Record {
    public:
        int getso() const { return so; }
        operator Key() {
            return Key(so);
        }
        friend istream& operator >> (istream& is, Record &r) {
            is >> r.so;
            return is;
        }
        friend ostream& operator << (ostream& os, const Record &r) {
            os << "So la: " << r.so;
            return os;
        }
        bool operator > (const Record &r) const {
            return so > r.so;
        }
    private:
        int so;
};
int main() {
    Record a[100];
    Key b[100];
    int n;
    cin >> n;
    cout << "Record la: \n";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cout << a[i] <<"\n";
    }
    for(int i = 0; i < n; i++) {
        b[i] = a[i];
    }
    for(int i = 0; i < n; i++) {
        cout << b[i] << "\n";
    }
    Key max = b[0];
    for(int i = 1; i < n; i++) {
        if(b[i] > max) {
            max = b[i];
        }
    }
    cout << "Max la: " << max << "\n";
    Key min = b[0];
    for(int i = 1; i < n; i++) {
        if(min > b[i]) {
            min = b[i];
        }
    }
    cout << "Max la: " << min;
}