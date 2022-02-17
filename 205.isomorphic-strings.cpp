/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> dic1, dic2;
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(dic1.find(s[i]) == dic1.end()){
                dic1[s[i]] = t[i];
            }else{
                if(dic1[s[i]] != t[i]) return false;
            }
            if(dic2.find(t[i]) == dic2.end()){
                dic2[t[i]] = s[i];
            }else{
                if(dic2[t[i]] != s[i]) return false;
            }
        }
        return true;
    }
};
// @lc code=end

