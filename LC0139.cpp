class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int maxL = 0;
        for(string str : wordDict){
            maxL = max(maxL, (int)str.length());
            //cout<<str.length();
        }
        unordered_set<string> dic(wordDict.begin(), wordDict.end());
        int l = s.length();
        vector<bool> OPT(l + 1, false); // OPT[i] means whether s(i - l-1) can be breaked.
        OPT[l] = true;
        for(int i = l - 1; i >= 0; i--){
            for(int j = min(l, i + maxL); j > i; j--){
                //cout<<s.substr(j, i - j);
                if(OPT[j] && dic.find(s.substr(i, j - i)) != dic.end()){
                    OPT[i] = true;
                    break;
                }
            }
            //cout<<OPT[i]<<' ';
        }
        return OPT[0];
    }
};
