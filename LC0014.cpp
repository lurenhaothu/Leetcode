class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int i = 0;
        while(i >= 0){
            char a = strs[0][i];
            //cout<<a;
            if(a == '\0') break;
            for(int j = 1; j < n; j++){
                if(strs[j][i] != a) return strs[0].substr(0, i);
            }
            i++;
        }
        return strs[0].substr(0, i);
    }
};
