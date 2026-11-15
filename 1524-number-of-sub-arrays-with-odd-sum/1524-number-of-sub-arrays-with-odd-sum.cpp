class Solution {
public:
    #define MOD 1000000007
    int numOfSubarrays(vector<int>& arr) {

        int n = arr.size();
        
        long long even = 1;
        long long odd = 0;
        long long sum = 0;
        long long ans = 0;
        
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(sum % 2 == 0) {
                ans = (ans + odd) % MOD;
                even++;
            }
            else {
                ans = (ans + even) % MOD;
                odd++;
            }
        }
        
        return ans;


    }
};