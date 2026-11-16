class Solution {
public:
    string digitSum(string s, int k) {

        while(1) {
            int n = s.size();
            if(n <= k) return s;
            string temp = "";
            for(int i = 0; i < n; i++){
                int j = i;
                int sum = 0;
                while(j < min(n, i+k)) {
                    sum += (s[j]-'0');
                    j++;
                }
                if(j > i) {
                    i = j - 1;
                }
                temp += to_string(sum);
            }
            s = temp;
        }

    }
};