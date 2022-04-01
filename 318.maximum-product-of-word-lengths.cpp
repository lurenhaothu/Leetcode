/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<pair<int, int>> dict;
        int maxpro = 0;
        //cout<<convert(words[3])<<endl;
        for(auto s : words){
            int query = convert(s);
            for(auto& p : dict){
                if(!shareChar(query, p.first))maxpro = max(maxpro, (int)s.length() * p.second);
            }
            dict.push_back(make_pair(query, s.length()));
        }
        return maxpro;
    }
    int convert(string& s){
        int res = 0;
        for(auto i : s) res |= (1<<(i - 'a'));
        return res;
    }
    bool shareChar(int& s1, int& s2){
        return (s1 & s2) != 0;
    }
};
// @lc code=end

