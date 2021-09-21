class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        int l = s.length(),level = 1, res = 0;
        for(int i = l - 1; i >=0; i--){
            if(roman[s[i]] == level){
                res += roman[s[i]];
            }else if(roman[s[i]] > level){
                res += roman[s[i]];
                level = roman[s[i]];
            }else{
                res -= roman[s[i]];
            }
        }
        return res;
    }
};
