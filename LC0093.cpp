class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.length() > 12) return res;
        DFS(s, 0, 0, res);
        return res;
    }
    void DFS(string s, int i, int dots, vector<string>& res){
        if(i == s.length()) return;
        if(dots == 3){
            if(s[i] == '0' && i != s.length() - 1) return;
            int k = 0;
            for(int j = i; j < s.length(); j++){
                k = k * 10 + (char)(s[j]) - 48;
            }
            if(k >= 0 && k <= 255) res.push_back(s);
            return;
        }else{
            if(i < s.length()){
                s.insert(i + 1, 1, '.');
                dots++;
                i = i + 2;
                DFS(s, i, dots, res);
                i = i - 2;
                s.erase(i + 1, 1);
                dots--;
            }
            if(i + 1 < s.length()){
                if(s[i] != '0'){
                    s.insert(i + 2, 1, '.');
                    dots++;
                    i = i + 3;
                    DFS(s, i, dots, res);
                    i = i - 3;
                    s.erase(i + 2, 1);
                    dots--;
                }
            }
            if(i + 2 < s.length()){
                int k = 0;
                for(int j = i; j <= i + 2; j++){
                    k = k * 10 + (char)(s[j]) - 48;
                }
                if(k >= 100 && k <= 255){
                    s.insert(i + 3, 1, '.');
                    dots++;
                    i = i + 4;
                    DFS(s, i, dots, res);
                    i = i - 4;
                    s.erase(i + 3, 1);
                    dots--;

                }
            }
        }
        return;
    }
};
