/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1);
        result[0] = 0;
        for(int i = 1; i <= n; i++){
            result[i] = result[i >> 1] + (i & 1);
        }
        return result;
    }
};
// @lc code=end

