class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> copy(strs);
        for(int i = 0; i < strs.size(); i++){
            sort(copy[i].begin(), copy[i].end());
        }
        unordered_map<string, vector<string>> dic;
        for(int i = 0; i < copy.size(); i++){
            dic[copy[i]].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto s : dic){
            res.push_back(s.second);
        }
        return res;
    }
};
