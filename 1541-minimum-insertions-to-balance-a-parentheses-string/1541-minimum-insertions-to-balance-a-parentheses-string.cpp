class Solution {
public:
    int minInsertions(string s) {
        
        int n = s.size();
        int count = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                count += 2;
                if(count & 1) {
                    cnt++;
                    count--;
                }
            }
            else {
                count--;
                if(count < 0) {
                    cnt++;
                    count = 1;
                }
            }
        }

        return count + cnt;

    }
};