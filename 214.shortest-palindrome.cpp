/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */

// @lc code=start
class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.empty()) return s;
        int n = s.length();
        string rs = s;
        reverse(rs.begin(), rs.end());
        string news = s + '#' + rs;
        int newn = news.length();
        vector<int> f(newn, 0);
        for(int i = 1; i < newn; i++){
            int t = f[i - 1];
            while(t > 0 && news[i] != news[t]){
                t = f[t - 1];
            }
            if(news[i] == news[t]) t++;
            f[i] = t;
        }
        int l = f.back();
        if(l == n) return s;
        string tail = s.substr(l, n - l);
        reverse(tail.begin(), tail.end());
        return tail + s;
    }
};
// @lc code=end

