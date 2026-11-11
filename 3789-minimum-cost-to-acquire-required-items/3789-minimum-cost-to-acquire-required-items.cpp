class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        long long ans = 0;

        long long a = 1LL* need1* cost1 + 1LL* need2* cost2;

        int x = min(need1, need2);

        long long b = 1LL* x * costBoth;

        b += 1LL* (need1 - x)* cost1;
        b += 1LL* (need2 - x)* cost2;

        long long c = 1LL* max(need1, need2)* costBoth;

        ans = min({a, b, c});

        return ans;

    }
};