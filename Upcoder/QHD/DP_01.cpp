Một tên trộm đã đột nhập thành công vào phòng khách của một ngôi nhà, tuy nhiên để tiến được vào phòng chứa két sắt hắn phải bước qua một đoạn cầu thang với n nấc thang, mỗi nấc thang chủ nhà đã thân thiện đóng thêm vài cây đinh chổng ngược để chào đón những tên trộm như hắn. Tên trộm ngán ngẫm nhưng đã bỏ công nên hắn phải cắn răng bước qua những nấc thang này. Hắn có 2 cách di chuyển, nếu đang ở bậc thang thứ i thì hắn có thể bước đến bậc thang thứ i+1 hoặc i + 2. 
Lưu ý: nền nhà phòng khách và nền nhà phía trên cầu thang không có đinh, chỉ có bậc thang là chứa đinh. Hắn có thể bước thẳng từ nền nhà phòng khách lên bậc thang thứ 2 mà không cần bước vào bậc thang thứ nhất. Tương tự hắn cũng có thể bước từ bậc thang kế cuối lên thằng nền nhà phía trên.
Input: 
- Dòng 1: một số nguyên dương n  đại diện cho số lượng bậc thang (n <= 3.105).
- Dòng 2: n số nguyên dương ai đại diện cho số đinh trên mỗi bậc thang (1 <= ai <= 109).
Output:
- Một dòng duy nhất là số đinh ít nhất mà tên trộm phải giẫm trong quá trình leo lên bậc thang.
Ví dụ:

Input

Output

7

2 6 1 3 9 3 2

9


Giải thích:
Tên trộm bước vào các bậc thang thứ 1, 3, 4, 6 và bỏ qua bậc thang cuối để bước lên nền nhà.
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
    rep(i, 0, n)
    {
        cin >> v[i];
    }
    vector<ll> dp(n, maxN);
    dp[0] = v[0];
    dp[1] = v[1];
    rep(i, 2, n)
    {
        dp[i] = v[i] + min(dp[i - 1], dp[i - 2]);
        //cout << v[i] << ' ' << dp[i - 1] << ' ' << dp[i - 2] << ' ' << dp[i] << '\n';
    }
    cout << min(dp[n - 1], dp[n - 2]);
    TGH;
}