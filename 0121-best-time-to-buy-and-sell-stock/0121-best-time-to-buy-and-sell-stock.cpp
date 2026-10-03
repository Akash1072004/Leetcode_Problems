class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<int> prefMin(n);
        // prefMin[0] = prices[0];
        // for(int i = 1; i < n; i++){
        //     prefMin[i] = min(prefMin[i-1], prices[i]);
        // }
        vector<int> suffMax(n);
        suffMax[n-1] = prices[n-1];
        for(int i = n-2; i >= 0; i--){
            suffMax[i] = max(suffMax[i+1], prices[i]);
        }
        int maxProfit = 0;
        int lastMin = prices[0];
        for(int i = 0; i < n-1; i++){
            int currMin = min(lastMin, prices[i]);
            int nextMax = suffMax[i+1];
            int profit = nextMax - currMin;
            maxProfit = max(maxProfit , profit);
        }
        return maxProfit;
    }
};