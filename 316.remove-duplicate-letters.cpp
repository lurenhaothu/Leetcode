/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> dict;
        unordered_map<char, int> present;
        for(auto i : s){
            dict[i]++;
            present[i] = 0;
        }
        string res;
        for(auto i : s){
            if(res.empty()){
                res += i;
                dict[i]--;
                present[i] = 1;
            }else if(present[i] == 1){
                dict[i]--;
            }else{
                while(!res.empty() && res.back() > i && dict[res.back()] != 0){
                    present[res.back()] = 0;
                    res.pop_back();
                }
                res += i;
                present[i] = 1;
                dict[i]--;
            }
        }
        return res;
    }
};
// @lc code=end

