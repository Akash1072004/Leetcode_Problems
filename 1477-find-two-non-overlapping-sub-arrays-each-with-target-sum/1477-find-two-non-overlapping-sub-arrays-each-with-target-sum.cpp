class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        
        int n = arr.size();
        int sum = 0;
        int i = 0, j = 0;
        int minLen = 1e9;
        int ans = 1e9;
        vector<int> v(n, 1e9);
        while(i < n && j < n) {
            sum += arr[j];
            while(i <= j && sum > target) {
                sum -= arr[i];
                i++;
            }
            if(sum == target) {
                if(i > 0) ans = min(ans, j-i+1+v[i-1]);
                minLen = min(minLen, j-i+1);
            }
            v[j] = minLen;
            j++;
        }
        return (ans == 1e9) ? -1 : ans;

    }
};