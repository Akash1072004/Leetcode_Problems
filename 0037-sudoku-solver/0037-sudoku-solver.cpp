class Solution {
public:
    bool fill(vector<vector<char>>&v, int r, int c, int num){
        for(int i = 0; i < 9; i++){
            if(v[r][i] - '0' == num)return false;
        }
        for(int i = 0; i < 9; i++){
            if(v[i][c] - '0' == num)return false;
        }
        int x = (r/3)*3;
        int y = (c/3)*3;
        for(int i = x; i < x+3; i++){
            for(int j = y; j < y+3; j++){
                if(v[i][j] - '0' == num)return false;
            }
        }
        return true;
    }
    bool f(vector<vector<char>>&v, int r, int c){
        if(r==9)return true;
        if(c==9)return f(v,r+1,0);
        if(v[r][c] != '.')return f(v,r,c+1);
        for(int i = 1; i <= 9; i++){
            if(fill(v,r,c,i)){
                v[r][c] = i + '0';
                bool check = f(v,r,c+1);
                if(check) return true;
                v[r][c] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        f(board,0,0);
        

        
    }
};