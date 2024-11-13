#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define ifile freopen("inp.txt", "r", stdin)
#define ofile freopen("out.txt", "w", stdout)
#define setup(a, c) memset(a, c, sizeof(a))
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FOD(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define rz resize
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Book {
    string book_id;
    string book_title;
    int year_of_publication;
    int price;

    friend istream& operator >> (istream &is, Book &book) {
        is >> book.book_id;
        is.ignore();
        getline(is, book.book_title);
        is >> book.year_of_publication;
        is >> book.price;
        return is;
    }

    friend ostream& operator << (ostream &os, Book book) {
        os << "[" << book.book_id << "] - " << book.book_title << "___" << book.year_of_publication << " //Price: " << book.price << "$";
        return os << '\n';
    }

    Book operator = (Book another) {
        this->book_id = another.book_id;
        this->book_title = another.book_title;
        this->year_of_publication = another.year_of_publication;
        this->price = another.price;
        return *this;
    }

    void setID (string id) {
        this->book_id = id;
    }
    
};

vector<Book> books;

void printBookList () {
    for (const Book& book : books) {
        cout << book;
    }
}

//a
void init () {
    int n; cin >> n;
    books.rz(n);
    FOR(i, 0, n - 1) {
        cin >> books[i];
    }
}

//b
void search (string x, string y) {
    bool found = false;
    FOR(i, 0, int(books.size()) - 1) {
        if (books[i].book_id == x) {
            found = true;
            books[i].setID(y);
        }
    }
    if (!found) 
        cout << "There are no books titled " << x << '\n';
    else {
        cout << "Changed the id of book " << x << " to " << y << '\n';
        cout << "After changed\n";
        printBookList();
    }
    
}

//c
int binarySearch (string x) {
    int left = 0, right = int(books.size()) - 1;
    while (left <= right) {
        int middle = (left + right)/2;
        if (books[middle].book_id == x) {
            return middle;
        }
        else if (books[middle].book_id > x) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    return -1;
}

void remove (int pos, string x) {
    if (pos != -1) {
        books.erase(begin(books) + pos);
        cout << "Deleted books with id = " << x << '\n';
    }
}

//d
void SelectionSort () {
    int idx, n = int(books.size());
    FOR(i, 0, n - 1) {
        idx = i;
        int a0 = stoi(books[idx].book_id);
        FOR(j, i + 1, n - 1) {
            int a1 = stoi(books[j].book_id);
            // if (books[j].book_id > books[idx].book_id) {
            //     idx = j;
            // }
            if (a1 > a0) idx = j;
        }
        if (idx != i)
            swap(books[i], books[idx]);
    }
}

//e
void InsertionSort () {
    int pos, n = int(books.size());
    Book data;
    FOR(i, 1, n - 1) {
        pos = i;
        data = books[pos];
        while (pos > 0 && books[pos-1].year_of_publication < data.year_of_publication) {
            books[pos] = books[pos-1];
            pos--;
        }
        books[pos] = data;
    }
}

//f
void bubbleSort () {
    int n = int(books.size()) - 1;
    FOR(i, 0, n - 2) {
        FOR(j, i + 1, n - 1) {
            if (books[i].book_title < books[j].book_title) {
                swap(books[i], books[j]);
            }
        }
    }
}

//g
int partition (int left, int right) {
    int i = left - 1, j = right + 1;
    int pivot = books[left].price;
    while (true) {
        do { --j; } while (books[j].price < pivot);
        do { ++i; } while (books[i].price > pivot);
        if (i >= j) {
            return j;
        }
        swap(books[i], books[j]);
    }
}

void quickSort (int left, int right) {
    if (left >= right) return;
    int mid = partition(left, right);
    quickSort(left, mid);
    quickSort(mid + 1, right);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ifile; ofile;

    init();
    cout << "Before\n";
    printBookList();

    string x, y;
    cin.ignore();
    getline(cin, x);
    getline(cin, y);
    search(x, y);

    string X;
    SelectionSort();
    cout << "After Selection Sort (Increasing by id)\n";
    printBookList();
    getline(cin, X);
    remove(binarySearch(X), X);
    cout << "After Delete " << X << "\n";
    printBookList();

    InsertionSort();
    cout << "After Insertion Sort (Decreasing by year of publication)\n";
    printBookList();

    bubbleSort();
    cout << "After Bubble Sort (Increasing by title)\n";
    printBookList();

    quickSort(0, int(books.size()) - 1);
    cout << "After Quick Sort(Decreasing by price)\n";
    printBookList();
    cerr << "\nProgram Executed Successfully!\n";
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}