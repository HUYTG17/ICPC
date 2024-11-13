#include <iostream>
using namespace std ;
// tăng dần
void Quicksort (int a[] , int left , int right){  
    int x ;                 
    int i , j ;            
    if (left >= right){
        return ;
    }                           
    x = a[(left + right)/2];             // x = a[1] = 6 
    i = left ;                           // i = 0   left = 0 
    j = right ;                          // j = 3   right = 3 
    while (i<j){                         // i = 2  
        while (a[i] < x) i++ ;           // j = 2
        while (a[j] > x) j-- ;          // i = 0  , left =0 (gọi hàm lần 1 ) 
        if ( i <=j){                     // j = 2  , right =2 ;
            swap (a[i] , a[j]);          // x = a[1] =5 
            i++ ;                         // i = 2 
            j-- ;                         // j = 0 ;
        }                                //  i=2  j =3 gọi hàm lần 2 
    }                                    // x = [2] = 7 ;
        Quicksort (a ,left ,j);          
        Quicksort (a , i , right);
}
/***
 n=4   
     4 6 7 5 -> 4 5 7 6 -> 4 5 6 7
     7 6 4 5 -> 7 6 5 4
pos  0 1 2 3
i = 0 j = 3;
x = a[1] = 6;
i = 0 j = 2;
i = 1 j = 1
qui 1
i = left = 0, j = 1
x = a[i] = 6;
i = 1, j = 1
i = 2, j = 0
qui 2
i = 2, right = 3;
x = a[2] = 4;
i = 2 j = 3;
i = 3 j = 2
 ***/
int main (){
    int a[100];
    int n ;
    cin>>n;
    for (int i=0 ; i<n;i++){
        cin>>a[i];
    }
    Quicksort (a,0,n-1);
    for (int i=0 ; i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0 ;
}

// giảm dần
#include <iostream>
using namespace std;
void QuickSort(int a[], int left, int right) {
    int x, i, j;
    if(left >= right) return;
    x = a[(left + right) / 2];
    i = left; j = right;
    while(i < j) {
        while(a[i] > x) i++;
        while(a[j] < x) j--;
        if(i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    }
    QuickSort(a, left, j);
    QuickSort(a, i, right);
}
int main() {
    int n, a[100];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    QuickSort(a, 0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}



/*
88 73 17 32 3 15 21 18
x = 32
18 21 17 15 3       32 73 88
x = 17
3 15    17    21 18            32 73 88
x = 3
3 15 17 18 21 32 73 88
*/


/*
n = 9
71 24 93 94 10 11 71 45 75
x = 10
75 45 71 11 10       94 93 24 71
x = 71
10 11 71    45 75      71  24 93    94

*/


void Quicksort (int a[] , int left , int right){  
    int x ;                 
    int i , j ;            
    if (left >= right){
        return ;
    }                           
    x = a[(left + right)/2];             // x = a[1] = 6 
    i = left ;                           // i = 0   left = 0 
    j = right ;                          // j = 3   right = 3 
    while (i<j){                         // i = 2  
        while (a[i] < x) i++ ;           // j = 2
        while (a[j] > x) j-- ;          // i = 0  , left =0 (gọi hàm lần 1 ) 
        if ( i <=j){                     // j = 2  , right =2 ;
            swap (a[i] , a[j]);          // x = a[1] =5 
            i++ ;                         // i = 2 
            j-- ;                         // j = 0 ;
        }                                //  i=2  j =3 gọi hàm lần 2 
    }                                    // x = [2] = 7 ;
        Quicksort (a ,left ,j);          
        Quicksort (a , i , right);
}

71 24 93 94 10 11 71 45 75
 
x = 10
i = 0, j = 8
=> i = 0, j = 4 (10 24 93 94 71 11 71 45 75) -> (i = 1, j = 3)

=> i = 1, j = 0 (10 24 93 94 71 11 71 45 75)
--------
i = 1, j = 8
x = 71
24 93 94 71 11 71 45 75

=> i = 2, j = 7 (24 45 94 71 11 71 93 75) -> (i = 3, j = 6)

=> i = 3, j = 6 (24 45 71 71 11 94 93 75) -> (i = 4, j = 5)

=> i = 4, j = 5 (24 45 71 11 71 94 93 75) -> (i = 5, j = 4)
                     
---------
24 45 71 11
x = 45
i = 1, j = 4
=> i = 2, j = 4 => (24 11 71 45) -> (i = 3, j = 3)
------------
i = 1, j = 3
24 11 71
x = 11
=> i = 1, j = 2 => (11 24 71) -> i = 2, j = 1
-----------
i = 2, j = 3
24 71
=> i = 2, j = 2 (24 71) -> (i = 3, j = 1)
-----------
i = 3, j = 4
71 45
x = 71
=> i = 3, j = 4 -> (45 71) -> (i = 4, j = 3)
-----------
71 94 93 75
x = 94
i = 5, j = 8
=> i = 6, j = 8 (71 75 93 94) -> (i = 7, j = 7)
-----------
i = 5, j = 7
71 75 93
x = 75
=> i = 6, j = 6 => (71 75 93) -> i = 7, j = 5
------------
i = 7, j = 8
93 94
x = 93
=> i = 7, j = 7 (93 94) -> (i = 8, j = 6)

10 11 24 45 71 71 75 93 94