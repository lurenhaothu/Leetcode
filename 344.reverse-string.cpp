/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        //reverse(s.begin(), s.end());
        for(int i = 0; i < s.size() - i - 1; i++){
            swap(s[i], s[s.size() - i - 1]);
        }
        return;
    }
};
// @lc code=end

