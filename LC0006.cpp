class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length(), r = numRows;
        if(r == 1) return s;
        string res;
        //int size = n > r ? r : n;
        for(int i = 0; i < n; i += 2 * r - 2){
            res += s[i];
        }
        if(r > 2){
            for(int i = 1; i < r - 1; i++){
                for(int j = i; j < n; j += 2 * r - 2){
                    res += s[j];
                    if(j + 2 * r - 2 - 2 * i < n) res += s[j + 2 * r - 2 - 2 * i];
                }
            }
        }
        for(int i = r - 1; i < n; i += 2 * r - 2){
            res += s[i];
        }
        return res;
    }
};
