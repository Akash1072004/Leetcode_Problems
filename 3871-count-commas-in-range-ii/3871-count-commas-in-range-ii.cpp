class Solution {
public:
    #define ll long long
    long long countCommas(long long n) {
        ll c = 0;
        if (n < 1000) return 0;
        else {
            if(n >= 1000){
                c += (min(n, 999999LL) - 1000 + 1);
            }
            if(n >= 1000000LL){
                c += (min(n, 999999999LL) - 1000000 + 1)*2;
            }
            if(n >= 1000000000LL){
                c += (min(n, 999999999999LL) - 1000000000 + 1)*3;
            }
            if(n >= 1000000000000LL){
                c += (min(n, 999999999999999LL)  - 1000000000000 + 1)*4;
            }
            if(n >= 1000000000000000LL){
                c += (n - 1000000000000000 + 1)*5;
            }
            return c;
        }
    }
};