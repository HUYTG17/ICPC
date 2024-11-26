#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insert(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void findMinDistancePairs(Node* head, vector<pair<int, int>>& pairs, int& minDistance) {
    minDistance = INT_MAX;
    for (Node* i = head; i != nullptr; i = i->next) {
        for (Node* j = i->next; j != nullptr; j = j->next) {
            int distance = abs(i->data - j->data);
            if (distance < minDistance) {
                minDistance = distance;
                pairs.clear();
                pairs.push_back({i->data, j->data});
            } else if (distance == minDistance) {
                pairs.push_back({i->data, j->data});
            }
        }
    }
}

int main() {
    ifstream inputFile("CONTRO.inp");
    if (!inputFile) {
        cerr << "Khong mo duoc file CONTRO.inp" << endl;
        return 1;
    }

    int n;
    inputFile >> n;
    Node* head = nullptr;
    for (int i = 0; i < n; ++i) {
        int value;
        inputFile >> value;
        insert(head, value);
    }
    inputFile.close();
    vector<pair<int, int>> pairs;
    int minDistance;
    findMinDistancePairs(head, pairs, minDistance);
    ofstream outputFile("CONTRO.out");
    if (!outputFile) {
        cerr << "Khong mo duoc file CONTRO.out" << endl;
        return 1;
    }

    outputFile << pairs.size() << " " << minDistance << endl;
    for (const auto& pair : pairs) {
        if (pair.first < pair.second)
            outputFile << "(" << pair.first << ", " << pair.second << ") ";
        else
            outputFile << "(" << pair.second << ", " << pair.first << ") ";
    }
    outputFile << endl;
    outputFile.close();
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
