class Solution {
public:
void brackets(string t,int x,int open,int close,vector<string>&s){
    if(close==x){
        s.push_back(t);
        return;
    }
    if(open<x)brackets(t+"(",x,open+1,close,s);
    if(close<open) brackets(t+")",x,open,close+1,s);
}
    vector<string> generateParenthesis(int n) {
        int x = n;
        vector<string>s;
        brackets("",x,0,0,s);
        return s;
    }
};