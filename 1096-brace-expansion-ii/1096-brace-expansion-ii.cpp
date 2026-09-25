class Solution {
public:

    set<string> get_unit(string expression, int n, int &i) {
        set<string> result;

        if(expression[i] == '{') {
            i++; // skip {

            result = perform_union(expression, n, i);

            i++; // skip }
        }
        else {
            result = {string(1, expression[i])};
            i++;
        }

        return result;
    }

    set<string> perform_concat(string expression, int n, int &i) {
        set<string> result = {""};

        while(i < n && (expression[i] == '{' || isalpha(expression[i]))) {

            set<string> temp = get_unit(expression, n, i);

            set<string> concatResult;

            for(string left : result) {
                for(string right : temp) {
                    concatResult.insert(left + right);
                }
            }

            result = concatResult;
        }

        return result;
    }

    set<string> perform_union(string expression, int n, int &i) {
        set<string> result;

        while(true) {

            set<string> temp = perform_concat(expression, n, i);

            result.insert(temp.begin(), temp.end());

            if(i < n && expression[i] == ',') {
                i++; // skip comma
            }
            else {
                break;
            }
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int n = expression.size();
        int i = 0;

        set<string> st = perform_union(expression, n, i);

        vector<string> result(st.begin(), st.end());

        return result;
        
    }
};