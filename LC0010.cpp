class Solution {
public:
    bool isMatch(string s, string p) {
        vector<char> pat;
        vector<int> star;
        int ls = s.length(), lp = p.length();
        for(int i = 0; i < lp; i++){
            pat.push_back(p[i]);
            if(i < lp - 1 && p[i + 1] == '*'){
                star.push_back(1);
                i++;
            }else{
                star.push_back(0);
            }
        }
        int lpat = pat.size();
        vector<vector<bool>> OPT(lpat + 1, vector<bool>(ls + 1, false));
        OPT[0][0] = true;
        for(int j = 1; j < lpat; j++){
            if(star[j - 1] == 1 && OPT[j - 1][0]) OPT[j][0] = 1;
            if(!star[j - 1]) break;
        }
        for(int j = 1; j <= lpat; j++){
            for(int i = 1; i <= ls; i++){
                if(star[j - 1] == 0){
                    if(pat[j - 1] == '.'){
                        OPT[j][i] = OPT[j - 1][i - 1];
                    }else{
                        OPT[j][i] = (pat[j - 1] == s[i - 1]) && OPT[j - 1][i - 1];
                    }
                }else{
                    if(pat[j - 1] == '.'){
                        OPT[j][i] = OPT[j][i - 1] || OPT[j - 1][i - 1] || OPT[j - 1][i];
                    }else{
                        OPT[j][i] = OPT[j - 1][i] || (OPT[j - 1][i - 1] && (pat[j - 1] == s[i - 1])) ||(OPT[j][i - 1] && (pat[j - 1] == s[i - 1]));
                    }
                }
            }
        }
        return OPT[lpat][ls];
    }
};
