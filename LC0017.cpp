class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> REF{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
        vector<vector<string>> res;
        if(digits.length() == 0) return vector<string>{};
        res.push_back(vector<string>{""});
        for(int i = 0; i < digits.length(); i++){
            vector<string> temp;
            for(int j = 0; j < res[res.size() - 1].size(); j++){
                for(int k = 0; k < REF[digits[i]].length(); k++){
                    temp.push_back(res[res.size() - 1][j] + REF[digits[i]][k]);
                }
            }
            res.push_back(temp);
        }
        return res[res.size() - 1];
    }
};
