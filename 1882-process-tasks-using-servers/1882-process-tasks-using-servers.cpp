class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        int n = servers.size();
        int m = tasks.size();

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> free;

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> busy;

        for(int i = 0; i < n; i++) {
            free.push({servers[i],i});
        }

        vector<int> ans(m);

        long long time = 0;

        for(int i = 0; i < m; i++) {
            time = max(time,(long long)i);
            if(free.empty()) {
                time = max(time,busy.top().first);
            }

            while(!busy.empty() && busy.top().first <= time) {

                int idx = busy.top().second;
                busy.pop();

                free.push({servers[idx],idx});
            }

            int idx = free.top().second;
            free.pop();
            ans[i] = idx;
            busy.push({time + tasks[i],idx});
        }

        return ans;


    }
};