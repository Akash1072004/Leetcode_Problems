class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {

        int n = seq.size();
        
        vector<int> ans(n);
        
        // ( ( ) ( ) )

        int depth = 0, maxDepth = 0;

        for(int i = 0; i < n; i++) {
            if(seq[i] == '(') depth++;
            else depth--;

            maxDepth = max(maxDepth, depth);
        }

        vector<int> v;

        for(int i = 0; i < n; i++) {
            if(seq[i] == '(') v.push_back(i);
            else {
                int currDepth = v.size();
                if(currDepth > maxDepth/2) {
                    ans[i] = 0;
                    ans[v.back()] = 0;
                }
                else {
                    ans[i] = 1;
                    ans[v.back()] = 1;
                }
                v.pop_back();
            }
        }

        return ans;

    }
};