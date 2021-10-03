class Solution {
public:
    bool isNumber(string s) {
        int eLoc = -1;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'e' || s[i] == 'E'){
                if(eLoc == -1) eLoc = i;
                else return false;
            }
        }
        if(eLoc == -1){
            int dotLoc = -1;
            for(int i = 0; i < s.length(); i++){
                if(s[i] == '.'){
                    if(dotLoc == -1) dotLoc = i;
                    else return false;
                }
            }
            if(dotLoc == -1){
                int start = 0, numCount = 0;
                if(s[0] == '-' || s[0] == '+') start = 1;
                for(int i = start; i < s.length(); i++){
                    if(s[i] > '9' || s[i] < '0') return false;
                    else numCount++;
                }
                if(numCount == 0) return false;
                return true;
            }else{
                if(s.length() == 1) return false;
                int start = 0, numCount = 0;
                if(s[0] == '-' || s[0] == '+') start = 1;
                for(int i = start; i < s.length(); i++){
                    if(s[i] == '.') continue;
                    else if(s[i] > '9' || s[i] < '0') return false;
                    else numCount++;
                }
                if(numCount == 0) return false;
                return true;
            }
        }else{
            if(eLoc == 0 || eLoc == s.length() - 1) return false;
            int dotLoc = -1;
            for(int i = 0; i < eLoc; i++){
                if(s[i] == '.'){
                    if(dotLoc == -1) dotLoc = i;
                    else return false;
                }
            }
            if(dotLoc == -1){
                int start = 0, numCount = 0;
                if(s[0] == '-' || s[0] == '+') start = 1;
                for(int i = start; i < eLoc; i++){
                    if(s[i] > '9' || s[i] < '0') return false;
                    else numCount++;
                }
                if(numCount == 0) return false;
            }else{
                if(eLoc == 1) return false;
                int start = 0, numCount = 0;
                if(s[0] == '-' || s[0] == '+') start = 1;
                for(int i = start; i < eLoc; i++){
                    if(s[i] == '.') continue;
                    else if(s[i] > '9' || s[i] < '0') return false;
                    else numCount++;
                }
                if(numCount == 0) return false;
            }
            int start = eLoc + 1, numCount = 0;
            if(s[start] == '-' || s[start] == '+') start++;
            for(int i = start; i < s.length(); i++){
                if(s[i] > '9' || s[i] < '0') return false;
                else numCount++;
            }
            if(numCount == 0) return false;
            return true;
        }
    }
};
