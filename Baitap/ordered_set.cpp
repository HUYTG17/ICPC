#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// Định nghĩa ordered_set kiểu int
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    ordered_set s;
    
    // Thêm phần tử vào ordered_set
    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(15);

    // Duyệt qua các phần tử (theo thứ tự tăng dần)
    for (int x : s) {
        cout << x << " "; // Kết quả: 5 10 15 20
    }
    cout << endl;

    // Tìm phần tử nhỏ nhất (0-based indexing)
    cout << "Phan tu nho nhat: " << *s.find_by_order(0) << endl; // Kết quả: 5

    // Tìm phần tử lớn nhất (k-th nhỏ nhất)
    cout << "Phan tu thu 3 nho nhat: " << *s.find_by_order(2) << endl; // Kết quả: 15

    // Đếm số phần tử nhỏ hơn 15
    cout << "So phan tu nho hon 15: " << s.order_of_key(15) << endl; // Kết quả: 2

    return 0;
}