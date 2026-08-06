class Solution {
public:
    int smallestNumber(int n, int t) {
        
        for(int i = n; i <= 1e5; i++) {
            int p = 1;
            int a = i;
            while(a) {
                p *= (a% 10);
                a /= 10;
            }
            if(p % t == 0) {
                return i;
            }
        }

        return -1;

    }
};