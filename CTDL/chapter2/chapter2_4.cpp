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

struct Subject {
    string subject_id;
    string subject_name;
    int subject_credits;
    double subject_score;

    friend istream& operator >> (istream &is, Subject &subject) {
        //cout << "Subject ID: ";
        is >> subject.subject_id;
        //cout << "Subject Name: ";
        is.ignore();
        getline(is, subject.subject_name);
        //cout << "Subject Credits: ";
        is >> subject.subject_credits;
        //cout << "Subject Score: ";
        is >> subject.subject_score;
        return is;
    }
};

struct Student {
    string student_id;
    string student_name;
    string student_date_of_birth;
    vector<Subject> student_subjects;

    friend istream& operator >> (istream &is, Student &student) {
        //cout << "ID of student: ";
        is >> student.student_id;
        //cout << "Name of student: ";
        is.ignore();
        getline(is, student.student_name);
        //cout << "Student's date of birth: ";
        is >> student.student_date_of_birth;
        //cout << "Student's number of subjects: ";
        int size; is >> size;
        student.student_subjects.rz(size);
        FOR(i, 0, size - 1) {
            //cout << "Subject" << i + 1 << "\n";
            is >> student.student_subjects[i];
        }
        return is;
    }

    friend ostream& operator << (ostream &os, Student student) {
        os << "ID: " << student.student_id << " | Name: " << student.student_name << " | Date Of Birth: " << student.student_date_of_birth << " | Avg: " << student.avg();
        return os << '\n';
    }

    Student operator = (Student another) {
        this->student_id = another.student_id;
        this->student_name = another.student_name;
        this->student_date_of_birth = another.student_date_of_birth;
        this->student_subjects = another.student_subjects;
        return *this;
    }

    void setStudentName (string name) {
        this->student_name = name;
    }

    double avg () {
        double sum = 0;
        for (Subject subject : student_subjects) {
            sum += subject.subject_score;
        }
        return (double)1.0*sum/(int)(student_subjects.size());
    }

    int getYearOfBirth () {
        size_t pos = student_date_of_birth.find('/');
        string temp = student_date_of_birth.substr(pos + 1);
        return stoi(temp.substr(temp.find('/') + 1));
    }
};

int n;
vector<Student> students;

//a
void init () {
    cin >> n;
    cin.ignore();
    students.rz(n);
    FOR(i, 0, n - 1) {
        cin >> students[i];
    }
}

//b
void search (string x, string y) {
    for (Student &student : students) {
        if (student.student_id == x) {
            student.setStudentName(y);
        }
    }
}

//c
void insertionSort () {
    FOR(i, 1, n - 1) {
        int pos = i;
        Student val = students[i];
        while (pos > 0 && students[pos-1].student_name < val.student_name) {
            students[pos] = students[pos-1];
            pos--;
        }
        students[pos] = val;
    }
}

void printListStudent () {
    cout << "---List Student---\n";
    for (const Student& student : students) {
        cout << student;
    }
}

//d
int binarySearch (string x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int middle = (left + right)/2;
        if (students[middle].student_name == x) {
            return middle;
        }
        else if (students[middle].student_name > x) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    return -1;
}

void remove (int pos) {
    if (pos != -1)
        students.erase(begin(students) + pos), n--;
}

//e
void SelectionSort () {
    int minVal;
    FOR(i, 0, n - 1) {
        minVal = i;
        FOR(j, i + 1, n - 1) {
            if (students[j].avg() < students[minVal].avg()) {
                minVal = j;
            }
        }
        if (minVal != i) {
            swap(students[i], students[minVal]);
        }
    }
}

//f
bool isValid (Student student) {
    for (Subject subject : student.student_subjects) {
        if (subject.subject_score < 5) return false;
    }
    return student.avg() >= 7;
}

void printListOfStudentsReceivingScholarships () {
    cout << "List Of Students Receiving Scholarships\n";
    int count = 1;
    FOR(i, 0, n - 1) {
        if (isValid(students[i])) {
            cout << count++ << ". " << students[i].student_name << " (" << students[i].avg() << ")\n";
        }
    }
}

//g
int Partition (int left, int right) {
    int i = left - 1, j = right + 1;
    int pivot = students[left].getYearOfBirth();
    while (true) {
        do { --j; } while (students[j].getYearOfBirth() > pivot);
        do { ++i; } while (students[i].getYearOfBirth() < pivot);
        if (i >= j) {
            return j;
        }
        swap(students[i], students[j]);
    }
}

void quickSort (int left, int right) {
    if (left >= right) return;
    int mid = Partition(left, right);
    quickSort(left, mid);
    quickSort(mid + 1, right);
}


int main () {
    /*ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);*/
    ifile; ofile;
    //a
    init();
    cout << "Before\n";
    printListStudent();
    //b
    string x, y;
    cin >> x;
    cin.ignore();
    getline(cin, y);
    search(x, y);
    //c
    insertionSort();
    cout << "After insertion sort\n";
    printListStudent();
    //d
    string X;
    getline(cin, X);
    cout << "After remove " << X << '\n';
    remove(binarySearch(X));
    //e
    SelectionSort();
    cout << "Selection sort with avg\n";
    //f
    printListOfStudentsReceivingScholarships();
    //g
    quickSort(0, n - 1);
    cout << "After quick sort\n";
    printListStudent();
    cerr << "\nProgram Executed Successfully!\n";
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}

/*Input
5
49.01.104.081
Nguyen Thi A Nha
07/12/1999
3
Toan
Co so toan trong CNTT
4
8.0
Hoa
Hoa dai cuong
3
9.75
Ly
Vat Ly luong tu
3
9.25
47.01.101.111
Pham Gia Bao
15/07/1995
2
GDQP
Duong loi quoc phong an ninh
2
8.5
GDTC
Cau long nang cao
1
10
46.01.103.044
Nhu Thich Thu
15/11/2001
4
GDCT
Triet hoc Mac - Lenin
3
8.0
GDCT
Kinh te chinh tri
3
7.7
GDCT
Chu nghia xa hoi khoa hoc
3
7.5
GDCT
Tu Tuong Ho Chi Minh
3
9.0
45.01.901.113
Vu Thi Cam Tu
11/11/1998
3
AV
Ngoai ngu 1
3
7.8
AV
Ngoai ngu 2
3
8.3
Toan
Toan roi rac
3
9.8
50.01.103.113
Em Nhi Cua Bao
11/12/2006
2
CNTT
Lap trinh co ban
3
7.5
CNTT
Danh sach lien ket quanvh
3
9.5
47.01.101.111
Tran Gia Huy
Nguyen Thi A Nha
*/