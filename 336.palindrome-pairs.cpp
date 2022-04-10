/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> res;
        unordered_map<string, int> dict;
        for(int i = 0; i < n; i++){
            dict[words[i]] = i;
        }
        for(int i = 0; i < n; i++){
            string& word = words[i];
            if(word.size() == 0) continue;
            string reverseword = word;
            reverse(reverseword.begin(), reverseword.end());
            if(reverseword != word && dict.find(reverseword) != dict.end()){
                res.push_back({i, dict[reverseword]});
                //res.push_back({dict[reverseword], i});
            }
            int m = word.size();
            bool repeat1 = true;
            bool repear2 = true;
            for(int j = 0; j < m; j++){
                if(isPalindrome(word, 0, j, repeat1)){
                    string suffix = word.substr(j + 1, m - j - 1);
                    reverse(suffix.begin(), suffix.end());
                    if(dict.find(suffix) != dict.end()) res.push_back({dict[suffix], i});
                }
                if(isPalindrome(word, m - j - 1, m - 1, repear2)){
                    string prefix = word.substr(0, m - j - 1);
                    reverse(prefix.begin(), prefix.end());
                    //cout<<prefix<<endl;
                    if(dict.find(prefix) != dict.end()) res.push_back({i, dict[prefix]});
                }
            }
            //cout<<"Next"<<endl;
        }
        return res;
    }
    bool isPalindrome(string& s, int start, int end, bool& flag){
        if(end - start + 1 >= 3 && flag){
            if(s[start] == s[start + 1] && s[end] == s[end - 1]) return true;
            else flag = false;
        }
        while(start < end){
            if(s[start] == s[end]){
                start++;
                end--;
            }else{
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

