class Solution {
public:
    int myAtoi(string s) {
        int start = 0, signal = 1, n = s.length();
        int res = 0;
        for(int i = 0; i < n; i++){
            if(start == 0){
                if(s[i] == ' ') continue;
                else if(s[i] == '+') start = 1;
                else if(s[i] == '-'){
                    start = 1;
                    signal = -1;
                }else if(s[i] >= '0' && s[i] <= '9'){
                    start = 1;
                    res = s[i] - '0';
                }else{
                    break;
                }
            }else if(start == 1){
                if(s[i] >= '0' && s[i] <= '9' && signal == 1){
                    if((res > INT_MAX / 10) || (res == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10 )) return INT_MAX;
                    res = (s[i] - '0') + res * 10;
                }else if(s[i] >= '0' && s[i] <= '9' && signal == -1){
                     if((res < INT_MIN / 10) || (res == INT_MIN / 10 && '0' - s[i] < INT_MIN % 10 )) return INT_MIN;
                    res = (s[i] - '0') * signal + res * 10;
                }else{
                    break;
                }
            }
        }
        return res;
    }
};
