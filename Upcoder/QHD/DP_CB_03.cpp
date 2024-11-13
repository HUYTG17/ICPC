Cho một xâu s gồm các ký tự số (mỗi ký tự nằm trong phạm vi '0' -> '9'). Mỗi số được tạo từ các ký tự trong phạm vi từ i đến j mà chia hết cho 2 thì được gọi là một số đẹp. Số đẹp được phép chứa các số 0 vô nghĩa ở đầu. Hãy tính tất cả các số đẹp trong phạm vi từ 0  đến r (0 <= i <= j <= r).
Input:
- Dòng 1 : Xâu s. (s.size() <= 2.105).
- Dòng 2: Một số nguyên dương q đại diện cho số truy vấn ( 1 <= q <= s.size()).
- Dòng 3: q số nguyên dương ri (0 <= ri < s.size()).
Output:
q số nguyên đại diện cho số lượng các số đẹp trong phạm vi từ 0 đến ri.
Ví dụ:

Input

Output

236472689

4

3 6 4 7

8 21 8 29 


Giải thích :
Ở truy vấn r = 3, phạm vi từ 0 -> 3 có các số chia hết cho 2 như sau :
2, 4, 6, 36, 64, 236, 364, 2364.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int q;
    cin >> s >> q;
    int n = s.size();
    vector<long long> beautiful(n, 0);
    for (int j = 0; j < n; j++) {
        if ((s[j] - '0') % 2 == 0) {
            beautiful[j] += j + 1; 
        }
        if (j > 0) {
            beautiful[j] += beautiful[j - 1]; 
    }

    }
    while (q--) {
        int r;
        cin >> r;
        cout << beautiful[r] << " ";
    }
    return 0;
}