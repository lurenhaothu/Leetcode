/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string str = s + ' ';
        vector<string> arr;
        int start = 0;
        unordered_map<char, string> dic;
        unordered_map<string, char> dic2;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == ' ') {
                arr.push_back(str.substr(start, i - start));
                start = i + 1;
                //cout<<"#"<<arr.back()<<"#"<<endl;
                int index = arr.size() - 1;
                if(index >= pattern.length()) return false;
                if(dic.find(pattern[index]) == dic.end()){
                    dic[pattern[index]] = arr.back();
                }else{
                    if(dic[pattern[index]] != arr.back()) return false;
                }
                if(dic2.find(arr.back()) == dic2.end()){
                    dic2[arr.back()] = pattern[index];
                }else{
                    if(dic2[arr.back()] != pattern[index]) return false;
                }
            }
        }
        if(arr.size() != pattern.length()) return false;
        return true;
    }
};
// @lc code=end

