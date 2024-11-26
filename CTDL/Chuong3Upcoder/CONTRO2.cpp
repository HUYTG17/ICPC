#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

void deleteNodesWithValue(Node*& head, int value) {
    while (head != nullptr && head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        Node* newNode = new Node(b);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    deleteNodesWithValue(head, k);

    // Đếm số phần tử
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }

    cout << count << endl;

    // In ra danh sách sau khi xoá
    current = head;
    while (current != nullptr) {
        cout << current->data << ' ';
        current = current->next;
    }

    // Giải phóng bộ nhớ
    current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
