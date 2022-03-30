/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //topological sorting
        vector<vector<int>> connection(n, vector<int>{});
        vector<int> deg(n, 0);
        unordered_set<int> remain;
        for(auto edge : edges){
            connection[edge[0]].push_back(edge[1]);
            connection[edge[1]].push_back(edge[0]);
            deg[edge[0]]++;
            deg[edge[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            remain.insert(i);
            if(deg[i] == 1) q.push(i);
        }
        while(remain.size() > 2){
            int m = q.size();
            for(int c = 0; c < m; c++){
                int cur = q.front();
                q.pop();
                deg[cur] = 0;
                remain.erase(cur);
                for(auto i : connection[cur]){
                    if(deg[i] != 0){
                        deg[i]--;
                        if(deg[i] == 1) q.push(i);
                    }
                }
            }
        }
        vector<int> res(remain.begin(), remain.end());
        return res;
    }
};
// @lc code=end

