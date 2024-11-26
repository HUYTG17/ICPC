#include <bits/stdc++.h>
using namespace std;

class LinkedListSeat;
class LinkedListCustomer; 

class NodeSeat {
    friend class LinkedListSeat;
private:
    int seat;
    NodeSeat* pNext;
public:
    NodeSeat(int x) : seat(x), pNext(nullptr) {}
    void display() {
        cout << "So ghe: " << seat << endl;
    }
};

class LinkedListSeat {
private:
    NodeSeat* pHead;
    NodeSeat* pTail;
    int size;
public:
    LinkedListSeat() : pHead(nullptr), pTail(nullptr), size(0) {}

    void AddTail(int _data) {
        NodeSeat* pAdd = new NodeSeat(_data);
        if (pHead == nullptr) {
            pHead = pTail = pAdd;
        } else {
            pTail->pNext = pAdd;
            pTail = pAdd;
        }
        size++;
    }

    void RemoveSeat(int seatNum) {
        NodeSeat* current = pHead;
        NodeSeat* prev = nullptr;

        while (current != nullptr && current->seat != seatNum) {
            prev = current;
            current = current->pNext;
        }

        if (current == nullptr) return;

        if (prev == nullptr) {
            pHead = current->pNext;
        } else {
            prev->pNext = current->pNext;
        }

        if (current == pTail) {
            pTail = prev;
        }

        delete current;
        size--;
    }

    void AddSeatBack(int seatNum) {
        AddTail(seatNum);
    }

    int getFirstSeat() {
        return pHead ? pHead->seat : -1;
    }

    int getSize() {
        return size;
    }

    void display() {
        NodeSeat* current = pHead;
        while (current != nullptr) {
            current->display();
            current = current->pNext;
        }
    }
};

class NodeCustomer {
    friend class LinkedListCustomer;
private:
    int seat;
    string name;
    NodeCustomer* pNext;
public:
    NodeCustomer(int seatNum, const string& customerName)
        : seat(seatNum), name(customerName), pNext(nullptr) {}

    void display() {
        cout << "So ghe: " << seat << ", Ten khach: " << name << endl;
    }
};

class LinkedListCustomer {
private:
    NodeCustomer* pHead;
    NodeCustomer* pTail;
    int size;
public:
    LinkedListCustomer() : pHead(nullptr), pTail(nullptr), size(0) {}

    void addCustomer(int seatNum, const string& customerName) {
        NodeCustomer* newNode = new NodeCustomer(seatNum, customerName);
        if (pHead == nullptr) {
            pHead = pTail = newNode;
        } else {
            pTail->pNext = newNode;
            pTail = newNode;
        }
        size++;
    }

    void removeCustomer(int seatNum) {
        NodeCustomer* current = pHead;
        NodeCustomer* prev = nullptr;

        while (current != nullptr && current->seat != seatNum) {
            prev = current;
            current = current->pNext;
        }

        if (current == nullptr) return;

        if (prev == nullptr) {
            pHead = current->pNext;
        } else {
            prev->pNext = current->pNext;
        }

        if (current == pTail) {
            pTail = prev;
            }

        delete current;
        size--;
    }

    void display() {
        NodeCustomer* current = pHead;
        while (current != nullptr) {
            current->display();
            current = current->pNext;
        }
    }
};

class NodeNumber {
    friend class QueueNumber;
private:
    int STT;
    NodeNumber* pNext;
public:
    NodeNumber(int x) : STT(x), pNext(nullptr) {}
    void display() {
        cout << "STT: " << STT << endl;
    }
};

class QueueNumber {
private:
    NodeNumber* front;
    NodeNumber* rear;
    int size;
    int nextSTT;
public:
    QueueNumber() : front(nullptr), rear(nullptr), size(0), nextSTT(1) {}

    void enqueue() {
        NodeNumber* temp = new NodeNumber(nextSTT);
        if (rear == nullptr) {
            front = rear = temp;
        } else {
            rear->pNext = temp;
            rear = temp;
        }
        size++;
        nextSTT++;
    }

    void dequeue(LinkedListSeat& seatList, LinkedListCustomer& customerList) {
        if (front == nullptr) {
    
            return;
        }

        NodeNumber* temp = front;
        front = front->pNext;

        if (seatList.getSize() > 0) {
            int seatNum = seatList.getFirstSeat();

            string customerName;
            cout << "Nhap ten khach hang cho ghe " << seatNum << ": ";
            cin >> customerName;

            customerList.addCustomer(seatNum, customerName);

            seatList.RemoveSeat(seatNum);
        }

        delete temp;
        size--;
    }

    void display() {
        NodeNumber* current = front;
        while (current != nullptr) {
            current->display();
            current = current->pNext;
        }
    }
};

int main() {
    LinkedListSeat seatList;
    LinkedListCustomer customerList;
    QueueNumber queue;
    int n;

    cout << "Nhap so luong ghe trong danh sach: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        seatList.AddTail(i);
    }

    int choice;
    do {
        system("cls");
        cout << "\nMenu:\n";
        cout << "1. Lay so (enqueue)\n";
        cout << "2. Mua ve (dequeue)\n";
        cout << "3. Huy ve (cancel ticket)\n";
        cout << "4. Hien thi danh sach ve da dat\n";
        cout << "5. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        choice = 0;
        cin >> choice;

        switch (choice) {
            case 1:
                if (seatList.getSize() == 0) {
                    cout << 1 << '\n';
                }
                else
                {
                    queue.enqueue();
                    cout << "Khach hang da lay so thanh cong.\n";
                }
                system("pause");
                break;

            case 2: {
                if (seatList.getSize() > 0) {
                    int seatNum = seatList.getFirstSeat();
                    string customerName;
                    cout << "Nhap ten khach hang cho ghe " << seatNum << ": ";
                    cin.ignore();
                    getline(cin, customerName); 
                    customerList.addCustomer(seatNum, customerName);
                    seatList.RemoveSeat(seatNum);
                    queue.dequeue(seatList, customerList);
                    cout << "Mua ve thanh cong cho " << customerName << ", so ghe: " << seatNum << ".\n";
                } else {
                    cout << "Khong con ghe trong de mua ve.\n";
                }
                system("pause");
                break;
            }

            case 3: {
                int seatNum;
                cout << "Nhap so ghe can huy: ";
                cin >> seatNum;
                customerList.removeCustomer(seatNum);
                seatList.AddSeatBack(seatNum);
                cout << "Ve da duoc huy thanh cong.\n";
                system("pause");
                break;
            }

            case 4:
                cout << "\nDanh sach ve da dat:\n";
                customerList.display();
                system("pause");
                break;

            case 5:
                cout << "Thoat chuong trinh.\n";
                system("pause");
                break;

            default:
                cout << "Lua chon khong hop le. Vui long nhap lai.\n";
                system("pause");
                break;
        }
    } while (choice != 0);

    return 0;
}