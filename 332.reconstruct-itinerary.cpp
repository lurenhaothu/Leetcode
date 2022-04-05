/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, map<string, int>> dict;
        for(auto ticket : tickets){
            dict[ticket[0]][ticket[1]]++;
        }
        int n = tickets.size();
        vector<string> res = {"JFK"};
        string cur = res.back();
        while(!dict[cur].empty()){
            res.push_back(dict[cur].begin()->first);
            if(dict[cur].begin()->second == 1) dict[cur].erase(dict[cur].begin());
            else dict[cur].begin()->second--;
            cur = res.back();
        }
        if(res.size() == n + 1) return res;
        //cout<<res.size()<<endl;
        vector<string> newres;
        while(newres.size() != n + 1){
            cur = res.back();
            while(!res.empty() && dict[cur].empty()){
                newres.push_back(res.back());
                res.pop_back();
                if(!res.empty()) cur = res.back();
            }
            while(!res.empty() && !dict[cur].empty()){
                res.push_back(dict[cur].begin()->first);
                if(dict[cur].begin()->second == 1) dict[cur].erase(dict[cur].begin());
                else dict[cur].begin()->second--;
                if(!res.empty())cur = res.back();
            }
        }
        reverse(newres.begin(), newres.end());
        return newres;
    }
};
// @lc code=end

