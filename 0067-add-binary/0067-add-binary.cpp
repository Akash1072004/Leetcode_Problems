class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        char c = '0'; // Addition of two Binary numbers which are in strings
        int as = a.size() - 1;
        int bs = b.size() - 1;
        for(int i = a.size()-1, j = b.size()-1; i >= 0 and j >= 0; i--, j--){
            char x = a[i]; char y = b[j];
            if(x != y) {
                if(c == '1') {
                    ans += "0";
                    c = '1';
                }
                else ans += "1";
            }
            else if(x == y and x == '1'){
                if(c == '1') ans += "1";
                else ans += "0";
                c = '1';
            }
            else {
                if(c == '1') ans += "1";
                else ans += "0";
                c = '0';
            }
            as = i;
            bs = j;
        }
        if(a.size() > b.size()){
            for(int i  = as-1; i >= 0; i--){
                if(a[i] == '1'){
                    if(c == '1'){
                        ans += "0";
                        c = '1';
                    }
                    else ans += a[i];
                }
                else {
                    if(c == '1'){
                        ans += "1";
                        c = '0';
                    }
                    else ans += "0";
                }
            }
        }
        if(b.size() > a.size()){
            for(int i  = bs-1; i >= 0; i--){
                if(b[i] == '1'){
                    if(c == '1'){
                        ans += "0";
                        c = '1';
                    }
                    else ans += b[i];
                }
                else {
                    if(c == '1'){
                        ans += "1";
                        c = '0';
                    }
                    else ans += "0";
                }
            }
        }
        if(c == '1') ans += "1";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};