/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for(auto i : nums){
            dict[i]++;
            
        }
        for(auto i : dict){
            q.push(make_pair(i.second, i.first));
            if(q.size() > k) q.pop();
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(get<1>(q.top()));
            q.pop();
        }
        return res;
    }
};
// @lc code=end

