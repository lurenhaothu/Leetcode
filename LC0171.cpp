class Solution {
public:
    int titleToNumber(string columnTitle) {
        int r = 0;
        for(int i = 0; i < columnTitle.length(); i++){
            r *= 26;
            r += columnTitle[i] - 64;
        }
        return r;
    }
};
