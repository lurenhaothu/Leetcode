/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> dic(26, 0);
        for(auto i : s) dic[i - 'a']++;
        for(auto i : t) dic[i - 'a']--;
        for(auto i : dic) if(i != 0) return false;
        return true;
    }
};
// @lc code=end

