class Solution {
public:
    bool checkDivisibility(int n) {
        
        int digitSum = 0;
        int digitProduct = 1;
        
        int x = n;
        while(n) {
            int ld = n % 10;
            digitSum += ld;
            digitProduct *= ld;
            n /= 10;
        }

        int sum = digitSum + digitProduct;

        if(x % sum == 0) return true;
        else return false;

    }
};