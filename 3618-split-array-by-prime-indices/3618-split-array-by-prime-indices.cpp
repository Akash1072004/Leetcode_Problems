class Solution {
public:
    #define ll long long
    bool isPrime(int n) {
        if(n < 2) return false;
        for(int i = 2; i* i <= n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }
    long long splitArray(vector<int>& nums) {

        int n = nums.size();

        ll a = 0;
        ll b = 0;
        for(int i = 0; i < n; i++) {
            if(isPrime(i)) a += nums[i];
            else b += nums[i];
        }

        return abs(a - b);
        
    }
};