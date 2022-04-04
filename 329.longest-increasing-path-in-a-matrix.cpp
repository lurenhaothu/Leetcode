/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> deg(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i > 0 && matrix[i - 1][j] < matrix[i][j]) deg[i][j]++;
                if(j > 0 && matrix[i][j - 1] < matrix[i][j]) deg[i][j]++;
                if(i < m - 1 && matrix[i + 1][j] < matrix[i][j]) deg[i][j]++;
                if(j < n - 1 && matrix[i][j + 1] < matrix[i][j]) deg[i][j]++;
                if(deg[i][j] == 0) q.push(make_pair(i, j));
            }
        }
        int roundnum = 0;
        while(!q.empty()){
            int queuesize = q.size();
            //cout<<queuesize;
            roundnum++;
            for(int itr = 0; itr < queuesize; itr++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(i > 0 && matrix[i - 1][j] > matrix[i][j]){deg[i - 1][j]--;if(deg[i - 1][j] == 0) q.push(make_pair(i - 1, j));}
                if(j > 0 && matrix[i][j - 1] > matrix[i][j]) {deg[i][j - 1]--;if(deg[i][j - 1] == 0) q.push(make_pair(i, j - 1));}
                if(i < m - 1 && matrix[i + 1][j] > matrix[i][j]) {deg[i + 1][j]--;if(deg[i + 1][j] == 0) q.push(make_pair(i + 1, j));}
                if(j < n - 1 && matrix[i][j + 1] > matrix[i][j]){deg[i][j + 1]--;if(deg[i][j + 1] == 0) q.push(make_pair(i, j + 1));}
                matrix[i][j] = INT_MAX;
            }
        }
        return roundnum;
    }
};
// @lc code=end

