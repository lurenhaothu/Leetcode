/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int, vector<vector<int>>> dic;
        // key: x ordinate, val: {op, height}, op: 0 begin, 1 end
        //dic[0] = vector<vector<int>>();
        for(auto i : buildings){
            dic[i[0]].push_back({0, i[2]});
            dic[i[1]].push_back({1, i[2]});
        }
        multiset<int> bset; //set of currently avaiable buidings
        vector<vector<int>> res;
        int hght = 0;
        for(auto itr = dic.begin(); itr != dic.end(); itr++){
            auto &ops = itr->second;
            for(auto op : ops){
                if(op[0] == 0) bset.insert(op[1]);
                else if(op[0] == 1) bset.erase(bset.find(op[1]));
            }
            int h = bset.empty() ? 0 : *bset.rbegin();
            if(h != hght){
                res.push_back({itr->first, h});
                hght = h;
            }
        }

        return res;
    }
};
// @lc code=end

