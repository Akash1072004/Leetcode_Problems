class Solution {
public:
    vector<vector<int>> up;
    vector<vector<long long>> sum;
    vector<int> nums;
    int LOG;
    long long getSum(int l, int r) {
        long long ans = 0;
        int cur = l;

        for(int j = LOG-1; j >= 0; j--) {
            if(up[j][cur] <= r) {
                ans += sum[j][cur];
                cur = up[j][cur];
            }
        }

        ans += 1LL * nums[cur] * (r-cur+1);
        return ans;
    }

    long long countNonDecreasingSubarrays(vector<int>& arr, int k) {
        
        nums = arr;
        int n = nums.size();

        vector<int> nxt(n, n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if(!st.empty()) {
                nxt[i] = st.top();
            }

            st.push(i);
        }

        LOG = 20;
        up.assign(LOG, vector<int>(n, n));
        sum.assign(LOG, vector<long long>(n, 0));

        for(int i = 0; i < n; i++) {
            up[0][i] = nxt[i];

            if(nxt[i] < n) {
                sum[0][i] = 1LL * nums[i] * (nxt[i]-i);
            }
        }

        for(int j = 1; j < LOG; j++) {
            for(int i = 0; i < n; i++) {
                int mid = up[j-1][i];

                if(mid < n) {
                    up[j][i] = up[j-1][mid];
                    sum[j][i] = sum[j-1][i] + sum[j-1][mid];
                }
            }
        }

        vector<long long> pref(n+1, 0);

        for(int i = 0; i < n; i++) {
            pref[i+1] = pref[i] + nums[i];
        }

        long long ans = 0;
        int r = 0;

        for(int l = 0; l < n; l++) {
            if(r < l) {
                r = l;
            }

            while(r+1 < n) {
                long long operations = getSum(l, r+1) - (pref[r+2]-pref[l]);

                if(operations <= k) {
                    r++;
                }
                else {
                    break;
                }
            }

            ans += (r-l+1);
        }

        return ans;

    }
};