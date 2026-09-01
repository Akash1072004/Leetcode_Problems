class Solution { 
public: 
    int minMoves(vector<string>& classroom, int energy) { 
         
        int m = classroom.size(); 
        int n = classroom[0].size(); 
 
        queue<pair<int, pair<int, pair<int, pair<int, int>>>>> q;
 
        int s_i = 0, s_j = 0; 
        for(int i = 0; i < m; i++) { 
            for(int j = 0; j < n; j++) { 
                if(classroom[i][j] == 'S') { 
                    s_i = i, s_j = j; 
                    break; 
                } 
            } 
        } 
 
        int litter = 0; 
        vector<vector<int>> vis(m, vector<int>(n, -1)); 
 
        for(int i = 0; i < m; i++) { 
            for(int j = 0; j < n; j++) { 
                if(classroom[i][j] == 'L') { 
                    vis[i][j] = litter; 
                    litter++; 
                } 
            } 
        } 
 
        int totalMask = (1 << litter)-1; 
 
        q.push({0, {energy, {0, {s_i, s_j}}}}); 
 
        vector<vector<vector<vector<int>>>> minMove(m, vector<vector<vector<int>>>(n, vector<vector<int>>(energy+1, vector<int>(1 << litter, 1e9)))); 
 
        minMove[s_i][s_j][energy][0] = 0; 
 
        int dr[] = {-1, +1, 0, 0}; 
        int dc[] = {0, 0, -1, +1}; 
 
        while(!q.empty()) { 
            auto it = q.front(); 
 
            int move = it.first; 
            int currEnergy = it.second.first; 
            int currMask = it.second.second.first; 
            int i = it.second.second.second.first; 
            int j = it.second.second.second.second; 
 
            q.pop(); 
 
            if(currMask == totalMask) return move; 
            if(currEnergy == 0) continue; 
 
            for(int d = 0; d < 4; d++) { 
                int newRow = i+dr[d]; 
                int newCol = j+dc[d]; 
                 
                if(newRow < 0 || newCol < 0 || newRow >= m || newCol >= n || classroom[newRow][newCol] == 'X') continue; 
 
                int newEnergy = currEnergy-1; 
 
                if(classroom[newRow][newCol] == 'R') newEnergy = energy; 
 
                int newMask = currMask; 
 
                if(classroom[newRow][newCol] == 'L') { 
                    int pos = vis[newRow][newCol]; 
                    newMask = newMask | (1 << pos); 
                } 
 
                if(minMove[newRow][newCol][newEnergy][newMask] > move+1) { 
                    minMove[newRow][newCol][newEnergy][newMask] = move+1; 
 
                    q.push({move+1, {newEnergy, {newMask, {newRow, newCol}}}}); 
                } 
            } 
        } 
 
        return -1; 
         
    } 
};