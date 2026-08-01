class Solution {
public:
    #define MOD 1000000007
    int dp[101][101][1801];
    int f(vector<string>& board, int i, int j, int score) {
        if(i == 0 && j == 0) {
            if(score == 0) return 1;
            else return 0;
        }
        if(score < 0) return 0;
        if(i < 0 || j < 0 || board[i][j] == 'X') return 0;
        if(dp[i][j][score] != -1) return dp[i][j][score];
        int ans = 0;
        int val = 0;
        if(board[i][j] >= '1' && board[i][j] <= '9') val = board[i][j] - '0';
        ans = (ans + f(board, i-1, j, score-val)) % MOD;
        ans = (ans + f(board, i, j-1, score-val)) % MOD;
        ans = (ans + f(board, i-1, j-1, score-val)) % MOD;
        return dp[i][j][score] = ans;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        
        int n = board.size();

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {n-1, n-1}}); // {score, {i, j}}

        vector<vector<int>> maxScore(n, vector<int>(n, -1));
        maxScore[n-1][n-1] = 0;

        int dr[] = {-1, -1, 0};
        int dc[] = {0, -1, -1};

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int curScore = it.first;
            int i = it.second.first;
            int j = it.second.second;

            if(curScore < maxScore[i][j]) continue;

            for(int d = 0; d < 3; d++) {
                int newRow = i + dr[d];
                int newCol = j + dc[d];

                if(newRow < 0 || newCol < 0 || newRow >= n || newCol >= n || board[newRow][newCol] == 'X') continue;

                int score = 0;
                if(board[newRow][newCol] >= '1' && board[newRow][newCol] <= '9') {
                    score = board[newRow][newCol] - '0';
                }
                if(maxScore[newRow][newCol] < curScore + score) {
                    maxScore[newRow][newCol] = curScore + score;
                    pq.push({maxScore[newRow][newCol], {newRow, newCol}});
                }
            }
        }

        memset(dp, -1, sizeof dp);
        int totalPath = f(board, n-1, n-1, maxScore[0][0]);

        if(totalPath == 0) return {0, 0};
        else return {maxScore[0][0], totalPath};

    }
};