class Solution {
public:
    string ans = "";
    bool f(string &left, vector<int>& count, int i, string target, bool isGreater, int n) {
        if(left.size() == n/2) {
            string right = left;
            reverse(right.begin(), right.end());

            string mid = "";
            if(n & 1) {
                for(int i = 0; i < 26; i++) {
                    if(count[i] & 1) mid += (i+'a');
                }
            }

            string curr = left + mid + right;
            if(curr > target) {
                ans = curr;
                return true;
            }
            return false;
        }
        
        for(int j = 0; j < 26; j++) {
            if(count[j]/2 == 0) continue;
            if(!isGreater && (j+'a') < target[i]) continue;

            left += (j+'a');
            count[j] -= 2;

            if(target[i] < (j+'a')) isGreater = true;
            bool res = f(left, count, i+1, target, isGreater, n);

            if(res) return true;

            // Backtacking
            left.pop_back();
            count[j] += 2;
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        
        int n = s.size();
        int oddFreq = 0;
        int evenFreq = 0;

        vector<int> count(26, 0);

        for(int i = 0; i < n; i++) {
            count[s[i]-'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(count[i] & 1) oddFreq++;
            else evenFreq++;
        }

        if(n & 1) {
            if(oddFreq != 1) return "";
        }
        else {
            if(oddFreq != 0) return "";
        }

        string left = "";
        f(left, count, 0, target, false, n);

        return ans;


    }
};