/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        DFS(res, temp, k, n, 9);
        return res;
    }
    void DFS(vector<vector<int>> &res, vector<int> &temp, int k, int n, int p){
        //k: remaining numbers
        //n: remaining sum
        //p: next number needed to be considered
        if(k == 0 && n != 0) return;
        else if(n == 0 && k == 0){
            res.push_back(temp);
            return;
        }else if(n != 0 && k == 0) return;
        if(p == 0) return;
        DFS(res, temp, k, n, p - 1);
        if(p <= n){
            temp.push_back(p);
            DFS(res, temp, k - 1, n - p, p - 1);
            temp.pop_back();
        }
        return;
    }
};
// @lc code=end

