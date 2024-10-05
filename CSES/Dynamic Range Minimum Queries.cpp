#include <iostream>

using namespace std;

int n, q;
const int inf =  1e9 + 7;
const int maxN = 1e6 + 7;
int st[4 * maxN], a[maxN];

void build(int id, int l, int r)
{
    if(l == r)
    {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = min(st[id * 2], st[id * 2 + 1]);
}
// 3 2 4 5 1 1 5 3
// 1 2 1 2 4 1 3 3 2 4 5 1 1 5 3
                    /*1 2 1 2 4 1 3 3 2 4 5 1 1 5 3
                    1 2 1 2 4 1 3 3         2 4 5 1 1 5 3
                1 2 1 2   4 1 3 3           2 4 5 1  1 5 3
              1 2    1 2    4 1   3 3     2 4  5 1    1 5    3
             1  2    1   2  4  1  3  3   2  4  5  1   1  5  3 */  
                
/*1 1 8
mid = 4
build 2, 1, 4
build 3, 5, 8
* build 2 1 4
mid = 2
build(4, 1, 2)
build(5, 3, 4)
*build(4, 1, 2)
mid = 1
build(8, 1, 1)
build(9, 2, 2)

*build(8, 1, 1) st[8] = a[1] = 3
*build(9, 2, 2) st[9] = a[2] = 2
*build(4, 1, 2) st[4] = 2

*build(5, 3, 4)  
mid = 3
build(10, 3, 3)
build(11, 4, 4)

build(10, 3, 3) st[10] = a[3] = 4
build(11, 4, 4) st[11] = a[4] = 5
build(5, 3, 4) st[5] = 4

build(2, 1, 4) st[2] = 2
*build(3, 5, 8)
mid = 6
build(6, 5, 6)
build(7, 7, 8)
*build(6, 5, 6) 
mid = 5
build(12, 5, 5) 
build(13, 6, 6)

build(12, 5, 5) st[12] = a[5] = 1
build(13, 6, 6) st[13] = a[6] = 1
build(6, 5, 6) st[6] = 1
*build(7, 7, 8)
mid = 7
build(14, 7, 7)
build(15, 8, 8)

build(14, 7, 7) st[14] = a[7] = 5
build(15, 8, 8) st[15] = a[8] = 3

build(7, 7, 8) st[7] = 3

build(3, 5, 8) st[3] = 1
build(1, 1, 8) st[1] = 1
*/
void update(int id, int l, int r, int pos, int val)
{
    if(l > pos || r < pos) return;
    if(l == r)
    {
        st[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = min(st[id * 2], st[id * 2 + 1]);
}

/*update(1, 1, 8, 3, 2)
mid = 4
update(2, 1, 4, 3, 2)
update(3, 5, 8, 3, 2)

*update(2, 1, 4, 3, 2)
mid = 2
update(4, 1, 2, 3, 2)
update(5, 3, 4, 3, 2)

update(4, 1, 2, 3, 2) return

*update(5, 3, 4, 3, 2)
mid = 3
update(10, 3, 3, 3, 2)
update(11, 4, 4, 3, 2)

update(10, 3, 3, 3, 2) st[10] = 2
update(11, 4, 4, 3, 2) st[11] = 2
update(5, 3, 4, 3, 2) = 2
update(2, 1, 4, 3, 2) = 2
update(3, 5, 8, 3, 2) return 
update(1, 1, 8, 3, 2) st[1] = 2
*/
int get(int id, int l, int r, int u, int v)
{
    if(l > v || r < u) return inf;
    if(l >= u && r <= v) return st[id];
    int mid = (l + r) / 2;
    int get1 = get(id * 2, l, mid, u, v);
    int get2 = get(id * 2 + 1, mid + 1, r, u, v);
    return min(get1, get2);
}
/*get(1, 1, 8, 2 , 4)
mid = 4
get(2, 1, 4, 2, 4)
get(3, 5, 8, 2, 4)
*get(2, 1, 4, 2, 4)
mid = 2
get(4, 1, 2, 2, 4)
get(5, 3, 4, 2, 4)
*get(4, 1, 2, 2, 4)
mid = 1
get(8, 1, 1, 2, 4)
get(9, 2, 2, 2, 4)

get(8, 1, 1, 2, 4) r < u 1 < 2 return inf
get(9, 2, 2, 2, 4) return st[9] = 2

get(4, 1, 2, 2, 4) min = 2

get(5, 3, 4, 2, 4) return st[5] = 4
get(2, 1, 4, 2, 4) = 2

get(3, 5, 8, 2, 4) return inf

return 2;*/


/*get(1, 1, 8, 5, 6)
mid = 5
get(2, 1, 5, 5, 6)
get(3, 6, 8, 5, 6)
*get(2, 1, 5, 5, 6)
mid = 3
get(4, 1, 3, 5, 6)
get(5, 4, 5, 5, 6)

get(4, 1, 3, 5, 6) return inf
*get(5, 4, 5, 5, 6) 
mid = 4
get(10, 4, 4, 5, 6)
get(11, 5, 5, 5, 6)

get(10, 4, 4, 5, 6) return inf
get(11, 5, 5, 5, 6) st[5] = 4
get(5, 4, 5, 5, 6) = 4
get(2, 1, 5, 5, 6) = 4

*get(3, 6, 8, 5, 6) 
mid = 7
get(6, 6, 7, 5, 6)
get(7, 8, 8, 5, 6)

*get(6, 6, 7, 5, 6)
mid = 6
get(6, 6, 6, 5, 6) st[6] = 1
get(7, 7, 7, 6, 6) inf

get(6, 6, 7, 5, 6) = 1

get(7, 8, 8, 5, 6) inf

get(3, 6, 8, 5, 6)  = 1

get(1, 1, 8, 5, 6) = 1
*/
/*get(1, 1, 8, 1, 8)
mid = 4
get(2, 1, 4, 1, 8)
get(3, 5, 8, 1, 8)

get(2, 1, 4, 1, 8) st[2] = 2
*get(3, 5, 8, 1, 8) st[3] = 1

get(1, 1, 8, 1, 8) = 1
*/
/*get(1, 1, 8, 3, 3)
mid = 4
get(2, 1, 4, 3, 3)
get(3, 5, 8, 3, 3)

get(2, 1, 4, 3, 3)
mid = 2
get(4, 1, 2, 3, 3) 
get(5, 3, 4, 3, 3)

get(4, 1, 2, 3, 3)
mid = 1
get(8, 1, 1, 3, 3)
get(9, 2, 2, 3, 3)

get(8, 1, 1, 3, 3) return inf
get(9, 2, 2, 3, 3) return inf
get(4, 1, 2, 3, 3) = inf

get(5, 3, 4, 3, 3)
mid = 3
get(10, 3, 3, 3, 3) st[10] = 4
get(11, 4, 4, 3, 3) inf
get(5, 3, 4, 3, 3) = 4

get(2, 1, 4, 3, 3) = 4
get(3, 5, 8, 3, 3) inf

get(1, 1, 8, 3, 3) = 4
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    while(q--)
    {
        int type, a, b;
        cin >> type >> a >> b;
        if(type == 1) update(1, 1, n, a, b);
        else cout << get(1, 1, n, a, b) << '\n';
    }
    return 0;
}