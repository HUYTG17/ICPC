Có n món quà. Hải được phép lấy quà từ trái sang phải theo quy luật. Nếu đã chọn quà ở vị trí lẻ thì món tiếp theo phải ở vị trí chẵn và ngược lại. Hãy tìm tổng giá trị quà cao nhất mà Hải có thể nhận.
Lưu ý: Vị trí quà được đánh số từ 0.
Input :
- Dòng 1: Số nguyên dương n ( 1 <= n <= 1000).
- Dòng 2: n số nguyên ai (|ai|<= 109).
Ouput:
Một dòng duy nhất là đáp án của bài toán.

Ví dụ:

Input

Output

10

9 -9 8 7 -1 2 -8 -6 1 1 

19





Giải thích :
Hải sẽ lấy các món quà ở vị trí 0 3 4 5 8 9.


#define ll long long
#define TGH return 0
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define rep1(i, a, b) for(int i = a; i <= b; ++i)
#define fastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#include <iostream>
#include <fstream>
#include <iomanip>
#include <climits>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ifile freopen("inp.txt", "r", stdin)
#define ofile freopen("out.txt", "w", stdout)
const int maxN = 2e5 + 7;
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
    fastIO;
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> dp(n);
    rep(i, 0, n)
    {
        cin >> v[i];
    }
    dp[0] = v[0];
    rep(i, 1, n)
    {
        dp[i] = v[i];
        for(int j = i - 1; j >= 0; j -= 2)
        {
            dp[i] = max(dp[i], dp[j] + v[i]);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
    TGH;
}