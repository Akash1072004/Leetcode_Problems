class Solution {
public:
    bool check(vector<int>& pos, int m, int d) {
        int count = 1;
        int last = pos[0];
        for(int i = 1; i < pos.size(); i++) {
            if(pos[i] - last >= d) {
                count++;
                last = pos[i];

                if(count == m)
                    return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& pos, int m) {

        sort(pos.begin(), pos.end());

        int low = 1;
        int high = 1e9;
        int ans = 0;

        while(low <= high) {
            int mid = low + (high-low) / 2;

            if(check(pos, m, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    
    }
};