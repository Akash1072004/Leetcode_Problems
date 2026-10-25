class Solution {
public:
    long long maxGCDScore(vector<int>& nums, int k) {
        
        int n = nums.size();
        long long ans = 0;

        for(int i = 0; i < n; i++) {
            int g = 0, mini = 32, cnt = 0;

            for(int j = i; j < n; j++) {
                g = gcd(g, nums[j]);

                int x = nums[j];
                int c = 0;

                while(x % 2 == 0) {
                    c++;
                    x /= 2;
                }

                if(c < mini) {
                    mini = c;
                    cnt = 1;
                } else if(c == mini) {
                    cnt++;
                }

                int len = j - i + 1;
                long long val = 1LL * len * g;

                if(cnt <= k) {
                    val *= 2;
                }

                ans = max(ans, val);
            }
        }

        return ans;


    }
};