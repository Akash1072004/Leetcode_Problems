class Solution {
public:
    int rs, ws;

    vector<vector<int>> dp;

    int countRobots(int start, int end, vector<int>& walls) {

        int left = lower_bound(walls.begin(), walls.end(), start) - walls.begin();

        int right = upper_bound(walls.begin(), walls.end(), end) - walls.begin();

        return right - left;
    }

    int f(vector<int>& robots, vector<int>& walls, vector<pair<int, int> >& ranges, int i, int prevFire) {

        if(i == rs) return 0;

        if(dp[i][prevFire] != -1) return dp[i][prevFire];

        int leftFire = 0, rightFire = ranges[i].second;

        if(prevFire == 0) {
            // previous robot fire left
            leftFire = ranges[i].first;
        }
        else {
            // previous robot fire right
            leftFire = max(ranges[i].first, ranges[i-1].second + 1);
        }

        int ans = 0;

        // leftFire
        ans = max(ans, countRobots(leftFire, robots[i], walls) + f(robots, walls, ranges, i+1, 0));

        // rightFire
        ans = max(ans, countRobots(robots[i], rightFire, walls) + f(robots, walls, ranges, i+1, 1));

        return dp[i][prevFire] = ans;

    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        
        rs = robots.size(); ws = walls.size();

        unordered_map<int, int> robotDist(rs);

        for(int i = 0; i < rs; i++) {
            robotDist[robots[i]] = distance[i];
        }

        vector<pair<int, int> > ranges(rs);

        sort(robots.begin(), robots.end());

        sort(walls.begin(), walls.end());

        for(int i = 0; i < rs; i++) {
            int leftRange = (i-1 >= 0) ? max(robots[i] - robotDist[robots[i]], robots[i-1]+1) : robots[i] - robotDist[robots[i]];
            int rightRange = (i+1 < rs) ? min(robots[i] + robotDist[robots[i]], robots[i+1]-1) : robots[i] + robotDist[robots[i]];

            ranges[i] = {leftRange, rightRange};
        }

        dp.resize(rs+1, vector<int> (3, -1));

        return f(robots, walls, ranges, 0, 0);


    }
};