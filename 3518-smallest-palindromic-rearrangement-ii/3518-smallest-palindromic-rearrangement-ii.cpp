class Solution {
public:
    #define ll long long
    ll ncr(int n, int r, int k) {
        if(r > n) return 0;

        r = min(r, n - r); // Important

        ll res = 1;
        for(int i = 1; i <= r; i++) {
            res = res* (n-r+i) / i;
            if(res >= k) return k;
        }

        return res;
    }
    string smallestPalindrome(string s, int k) {
        
        int n = s.size();
        vector<int> v(26, 0);
        string mid = "";
        for(char c : s) {
            v[c-'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(v[i] & 1) {
                mid = char(i+'a');
                v[i]--;
                v[i] /= 2;
            }
            else v[i] /= 2;
        }

        string left = "";
        int halfLen = n/2;
        int totalLen = halfLen;

        for(int i = 0; i < halfLen; i++) {

            bool fillChar = false;
            for(int j = 0; j < 26; j++) {
                if(v[j] == 0) continue;

                ll ways = 1;

                v[j]--; // Fix the ith character 
                int rem = totalLen - 1;

                // Calculate ways after fixing the ith character
                for(int c = 0; c < 26; c++) {
                    char ch = char(c+'a');
                    int freq = v[c];

                    ways *= ncr(rem, freq, k);
                    if(ways >= k) break;
                    rem -= freq; //  remaining length after filling this all characters
                }

                if(ways >= k) {
                    left += char(j+'a');
                    fillChar = true;
                    totalLen--;
                    break;
                }
                else {
                    k -= ways;
                    v[j]++; // restore the ith char fix
                }
                if(k < 0) return "";
            }

            if(!fillChar) return "";
        }

        string right = left;
        reverse(right.begin(), right.end());

        string ans = left + mid + right;

        return ans;

    }
};