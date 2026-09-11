class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        
        int n = digits.size();
        unordered_set<string> st;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {

                    if(i == j || j == k || i == k) continue;

                    int firstNum = digits[i];
                    int secondNum = digits[j];
                    int thirdNum = digits[k];
                    
                    if(firstNum == 0) continue;
                    if(thirdNum & 1) continue;

                    string num = to_string(firstNum) + to_string(secondNum) + to_string(thirdNum);

                    st.insert(num);
                }
            }
        }

        return st.size();

    }
};