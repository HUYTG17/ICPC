#define f(i, a, b) for(int i = a; i <= b; i++)
#include <iostream>

using namespace std;

void solve(int n) 
{
    if(n == 0)
    {
        cout << 0;
    }
    else 
    {
        int sum = 0;
        if(n < 0) 
        {
            f(i, 1, abs(n)) 
            {
                if(abs(n) % i == 0)
                {
                    sum += i;
                }
            }
        }
        else 
        {
            f(i, 1, n)
            {
                if(n % i == 0)
                {
                    sum += i;
                }
            }
        }
        cout << sum;
    }
}

int main() 
{
    int n; 
    cin >> n;
    solve(n);
    return 0;
}