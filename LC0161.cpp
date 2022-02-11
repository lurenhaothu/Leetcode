class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.length() == t.length()){
            int dif = 0;
            for(int i = 0; i < s.length(); i++){
                if(s[i] != t[i]) dif++;
                if(dif > 1) return false;
            }
            return (dif == 1);
        }else if(s.length() - t.length() == 1){
            int dif = 0;
            for(int i = 0; i < s.length(); i++){
                if(dif == 0 && s[i] != t[i]) dif++;
                else if(dif == 1 && s[i] != t[i - 1]) return false;
            }
            return true;
        }else if(t.length() - s.length() == 1){
            int dif = 0;
            for(int i = 0; i < t.length(); i++){
                if(dif == 0 && s[i] != t[i]) dif++;
                else if(dif == 1 && s[i - 1] != t[i]) return false;
            }
            return true;
        }
        return false;
    }
};
