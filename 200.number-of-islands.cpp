/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int ORD = 500;
        unordered_set<int> ones;
        queue<int> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1') ones.insert(i * ORD + j);
            }
        }
        int res = 0;
        if(ones.empty()) return 0;
        //q.push(*ones.begin());
        //ones.erase(q.back());
        //res++;
        while(!ones.empty()){
            q.push(*ones.begin());
            ones.erase(q.back());
            res++;
            while(!q.empty()){
                int qf = q.front();
                q.pop();
                if(ones.find(qf - 1) != ones.end()){
                    q.push(qf - 1);
                    ones.erase(qf - 1);
                }
                if(ones.find(qf + 1) != ones.end()){
                    q.push(qf + 1);
                    ones.erase(qf + 1);
                }
                if(ones.find(qf - ORD) != ones.end()){
                    q.push(qf - ORD);
                    ones.erase(qf - ORD);
                }
                if(ones.find(qf + ORD) != ones.end()){
                    q.push(qf + ORD);
                    ones.erase(qf + ORD);
                }
            }
        }
        return res;
    }
};
// @lc code=end

