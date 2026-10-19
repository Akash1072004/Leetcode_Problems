class Solution {
public:
    string removeKdigits(string num, int k) {

        int n = num.size();
        string ans = "";

        for(int i = 0; i < n; i++) {
            while(!ans.empty() && k > 0 && ans.back() > num[i]) {
                ans.pop_back();
                k--;
            }

            ans.push_back(num[i]);
        }

        while(k > 0) {
            ans.pop_back();
            k--;
        }

        int i = 0;
        while(i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i);

        if(ans.empty()) return "0";

        return ans;


    }
};
