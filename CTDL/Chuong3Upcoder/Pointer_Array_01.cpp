#include <iostream>
#include <cstdlib>

using namespace std;

bool isSymmetric(int *arr, int size) {
    for (int i = 0; i < size / 2; ++i) {
        if (arr[i] != arr[size - 1 - i])
            return false;
    }
    return true;
}

int main() {
    int size;
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    if (isSymmetric(arr, size)) {
        cout << "mang doi xung" << endl;
    } else {
        cout << "mang khong doi xung" << endl;
        // In các cặp phần tử làm cho mảng không đối xứng
        for (int i = 0; i < size / 2; ++i) {
            if (arr[i] != arr[size - 1 - i])
                cout << arr[i] << " " << arr[size - 1 - i] << endl;
        }
    }

    delete[] arr;
    return 0;
}
