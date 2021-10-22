class Solution {
public:
    string scopy;
    vector<string> res;
    string r;
    int l;
    int maxL;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        maxL = 0;
        for(string str : wordDict){
            maxL = max(maxL, (int)str.length());
            //cout<<str.length();
        }
        unordered_set<string> dic(wordDict.begin(), wordDict.end());
        l = s.length();
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
        scopy = s;
        DFS(dic, 0, OPT);
        return res;
    }
    void DFS(unordered_set<string> &dic, int start, vector<bool> OPT){
        if(start == l){
            res.push_back(r);
            return;
        }
        for(int j = start + 1; j <= min(start + maxL, l); j++){
            if(!OPT[j]) continue;
            else{
                if(dic.find(scopy.substr(start, j - start)) != dic.end()){
                    if(j == l){
                        r += scopy.substr(start, j - start);
                        DFS(dic, j, OPT);
                        r.erase(r.end() - j + start, r.end());
                    }else{
                        r += scopy.substr(start, j - start);
                        r += ' ';
                        DFS(dic, j, OPT);
                        r.erase(r.end() - j + start - 1, r.end());
                    }
                }
            }
        }
    }
};
