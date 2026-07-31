class Solution {
public:
    vector<int> topoSort(vector<int> graph[], vector<int>& indegree, int size) {
        queue<int> qu;
        for(int i = 0; i < size; i++) {
            if(indegree[i] == 0) qu.push(i);
        }

        vector<bool> vis(size, false);

        vector<int> order;

        while(!qu.empty()) {
            int node = qu.front();
            qu.pop();

            order.push_back(node);
            vis[node] = true;
            for(auto it : graph[node]) {
                indegree[it]--;
                if(!vis[it] && indegree[it] == 0) {
                    qu.push(it);
                }
            }
        }

        if(order.size() != size) return {};
        else return order;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {

        // Assign every node to group which has -1
        for(int i = 0; i < n; i++) {
            if(group[i] == -1) {
                group[i] = m++;
            }
        }
        
        vector<int> itemsGraph[n];
        vector<int> itemsIndegree(n, 0);

        // create a BeforeIteam to iteam itemsGraph
        for(int i = 0; i < n; i++) {
            vector<int> u = beforeItems[i];

            if(u.size() != 0) {
                for(auto it : u) {
                    itemsGraph[it].push_back(i);
                    itemsIndegree[i]++;
                }
            }
        }

        // find the order according to this itemsGraph
        vector<int> itemsOrder = topoSort(itemsGraph, itemsIndegree, n);

        // now make a graph b/w group and items
        vector<int> groupGraph[m];
        vector<int> groupIndegree(m, 0);

        for(int i = 0; i < n; i++) {
            vector<int> previtems = beforeItems[i];

            if(previtems.empty()) continue;

            for(auto it : previtems) {
                int previtemsGroup = group[it];
                int curritemsGroup = group[i];

                if (previtemsGroup != curritemsGroup) {
                    groupGraph[previtemsGroup].push_back(curritemsGroup);
                    groupIndegree[curritemsGroup]++;
                }
            }
        }

        vector<int> groupOrder = topoSort(groupGraph, groupIndegree, m);

        if(itemsOrder.empty()) return {};
        if(groupOrder.empty()) return {};

        vector<vector<int> > itemsInOrder(m);
        unordered_map<int, int> groupIndex;

        for(int i = 0; i < m; i++) {
            groupIndex[groupOrder[i]] = i;  // assign group to their index
        }

        for(int i = 0; i < n; i++) {
            int groupNumber = group[itemsOrder[i]];


            int idx = groupIndex[groupNumber];
            itemsInOrder[idx].push_back(itemsOrder[i]);
        }

        vector<int> ans;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < itemsInOrder[i].size(); j++) {
                ans.push_back(itemsInOrder[i][j]);
            }
        }

        return ans;

    }
};