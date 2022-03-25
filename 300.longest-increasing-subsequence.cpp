/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        stack<int> st;
        for(auto i : nums){
            if(st.empty()) st.push(i);
            else if(st.top() < i) st.push(i);
            else{
                while(st.)
            }
        }
    }
};
// @lc code=end

