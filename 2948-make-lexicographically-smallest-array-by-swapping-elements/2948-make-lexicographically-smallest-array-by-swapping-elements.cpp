class Solution {
public:
    vector<int> vis;
    void dfs(vector<int> graph[], int node, vector<int>& val, vector<int>& index, vector<int>& nums, unordered_map<int, vector<int>>& mp) {
        if(vis[node]) return;
        vis[node] = 1;
        val.push_back(nums[node]);
        index.push_back(mp[nums[node]].back());
        mp[nums[node]].pop_back();

        for(auto it : graph[node]) {
            if(!vis[it]) {
                dfs(graph, it, val, index, nums, mp);
            }
        }
    }
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n = nums.size(); 
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        sort(nums.begin(), nums.end());

        vector<int> graph[n];
        int a = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i]-nums[i-1] <= limit) {
                graph[a].push_back(i);
                graph[i].push_back(a);
            }
            else {
                a = i;
            }
        }

        // if(nums[n-1]-nums[n-2] > limit) {
        //     graph[n-1] = {};
        // }

        vis.assign(n, 0);
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                vector<int> val;
                vector<int> index;
                dfs(graph, i, val, index, nums, mp);

                sort(index.begin(), index.end());
                sort(val.begin(), val.end());

                for(int j = 0; j < index.size(); j++) {
                    ans[index[j]] = val[j];
                }
            }
        }

        return ans;

    }
};