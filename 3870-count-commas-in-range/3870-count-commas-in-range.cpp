class Solution {
public:
    int countCommas(int n) {
        int c = 0;
        if (n < 1000) return 0;
        else {
            for(int i = 1000; i <= n; i++){
                string s = to_string(n);
                int l = (s.size() - 1)/3;
                c += l;
            }
            return c;
        }
    }
};