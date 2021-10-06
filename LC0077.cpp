class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        DFS(n, k, 1, cur, res);
        return res;
    }
    void DFS(int n, int k, int begin, vector<int>& cur, vector<vector<int>>& res){
        if(k == 0){
            res.push_back(cur);
            return;
        }
        if(n - begin + 1 < k) return;
        else{
            cur.push_back(begin);
            DFS(n, k - 1, begin + 1, cur, res);
            cur.pop_back();
            DFS(n, k, begin + 1, cur, res);
        }
    }
};
