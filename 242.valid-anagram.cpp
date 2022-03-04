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

(exp(t/tau)*int((exp(-x/tau)*(exp(x/tau) - 1)^((b*tau)/v0)*(exp(x/tau) + 1)^((b*tau)/v0)*(a*v0^2 + a*v0^2*exp(x/tau) + 

D*b*tau*exp((2*x)/tau)))/(tau*v0^2*(exp(x/tau) + 1)), x, 0, t, 'IgnoreSpecialCases', true))/((exp(t/tau) - 1)^((b*tau)/v0 + 1)*(exp(t/tau) + 1)^((b*tau)/v0))