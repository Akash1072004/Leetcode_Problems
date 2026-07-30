class Solution {
public:
    int reverse(int x) {
        long long r = 0;
        while(x != 0){
            r = r*10 + (x%10);
            if(r < INT_MIN or r > INT_MAX) return 0;
            x /= 10;
        }
        return r;


    }
};