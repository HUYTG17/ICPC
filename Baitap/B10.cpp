// Bài 10 : Cho một dãy các từ, tìm các từ là từ đảo ngược của nhau .
// Ví dụ :
// Input :
// 6
// abc cba def fed ghi ijk
// Output :
// (abc, cba)
// (def, fed)
// (def, fed)
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	set<string> se;
	for(int i = 0; i < n; i++) {
        string s; cin >> s;
        string rs = s;
        reverse(rs.begin(), rs.end());
        if(se.find(rs) != se.end()) {
            cout << "(" << rs << ", " << s << ")\n";
        }
        se.insert(s);
	}
}