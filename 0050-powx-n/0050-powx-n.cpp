class Solution {
public:
    double f(double x, long long n) {
        if(n == 0) return 1;
        double result = f(x, n/2);
        if(n & 1) return x* result* result;
        else return result* result;
    }
    double myPow(double x, int n) {

        long long b = n;

        if(b < 0) {
            return 1.0 / f(x, -b);
        }
        
        return f(x, n);

    }
};