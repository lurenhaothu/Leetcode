class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 1){
            if(s[0] >= '1' && s[0] <= '9') return 1;
            else return 0;
        }
        vector<int> OPT;
        OPT.push_back(1);
        if(s[0] >= '1' && s[0] <= '9') OPT.push_back(1);
        else OPT.push_back(0);
        for(int i = 1; i < s.length(); i++){
            if(s[i] >= '1' && s[i] <= '9') OPT.push_back(OPT[i]);
            else OPT.push_back(0);
            if(s[i - 1] == '1'){
                OPT[i + 1] += OPT[i - 1];
            }else if(s[i - 1] == '2'){
                if(s[i] >= '0' && s[i] <= '6'){
                    OPT[i + 1] += OPT[i - 1];
                }
            }
        }
        return OPT.back();
    }
};
