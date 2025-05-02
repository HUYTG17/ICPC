class Solution {
public:
    double myPow(double x, long long n) {
        while(n < 0)
        {
            x = 1 / x;
            n = -n;
        }
        double res = 1;
        while(n)
        {
            if(n % 2) res *= x;
            x *= x;
            n /= 2;
        }
        return res;
    }
};
