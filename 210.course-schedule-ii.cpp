/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses, m = prerequisites.size();
        vector<int> res;
        queue<int> q;
        vector<int> deg(n, 0);
        vector<vector<int>> edge(n);
        for(auto i : prerequisites){
            deg[i[0]]++;
            edge[i[1]].push_back(i[0]);
        }
        for(int i = 0; i < n; i++){
            if(deg[i] == 0){
                q.push(i);
                res.push_back(i);
            }
        }
        while(!q.empty()){
            int p = q.front();
            q.pop();
            for(auto i : edge[p]){
                deg[i]--;
                if(deg[i] == 0){
                    res.push_back(i);
                    q.push(i);
                }
            }
        }
        if(res.size() == n) return res;
        else return {};
    }
};
// @lc code=end

