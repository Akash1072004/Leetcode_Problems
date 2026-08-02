class Solution {
public:
    #define ll long long
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {

        int n = tasks.size();
        int m = shifts.size();

        vector<int> ans(m, 0);
        vector<ll> pre(n, 0);
        pre[0] = tasks[0];
        for(int i = 1; i < n; i++) {
            pre[i] = pre[i-1]+(ll)tasks[i];
        }
        int a = tasks[0];
        int i = 0;
        ll t = 0;
        for(int j = 0; j < m; j++) {
            t += shifts[j];
            if(t < pre[n-1]) {
                int idx = 0;
                int l = 0, h = n-1;
                while(l <= h) {
                    int mid = l+(h-l)/2;
                    if(pre[mid] > t) {
                        h = mid-1;
                        idx = mid;
                    }
                    else {
                        l = mid+1;
                    }
                }
                ans[j] = n-idx;
            }
            else {
                // t = t-(t/pre[n-1])* pre[n-1];
                // if(t == 0) ans[j] = 0;
                // else {
                //     int idx = 0;
                //     int l = 0, h = n-1;
                //     while(l <= h) {
                //         int mid = l+(h-l)/2;
                //         if(pre[mid] > t) {
                //             h = mid-1;
                //             idx = mid;
                //         }
                //         else {
                //             l = mid+1;
                //         }
                //     }
                //     ans[j] = n-idx;
                // }
                ans[j] = 0;
                t = 0;
            }
        }
        return ans;
        
    }
};