class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 1) return true;
        int i = 0, j = s.length() - 1;
        while(i < j){
            //cout<<i<<j<<endl;
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] += 32;
                continue;
            }else if(s[i] < '0' || (s[i] > '9' && s[i] < 'A') || (s[i] > 'Z' && s[i] < 'a') || s[i] >'z'){
                i++;
                continue;
            }
            if(s[j] >= 'A' && s[j] <= 'Z'){
                s[j] += 32;
                continue;
            }else if(s[j] < '0' || (s[j] > '9' && s[j] < 'A')  || (s[j] > 'Z' && s[j] < 'a') || s[j] >'z'){
                j--;
                continue;
            }
            //cout<<s[i]<<s[j]<<endl;
            if(s[i] == s[j]){
                i++;
                j--;
                continue;
            }
            else return false;
        }
        return true;
    }
};
