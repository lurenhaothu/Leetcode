class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> parenthese, pr;
        int maxlen = 0, n = s.length();
        for(int i = 0; i < n; i++){
            if(parenthese.size() == 0){
                if(s[i] == '('){
                    parenthese.push_back(1);
                }else{
                    parenthese.push_back(-1);
                }
                pr.push_back(i);
            }else{
                if(s[i] == '('){
                    parenthese.push_back(1);
                    pr.push_back(i);
                }else if(s[i] == ')'){
                    if(parenthese[parenthese.size() - 1] == 1){
                        parenthese.pop_back();
                        pr.pop_back();
                    }else{
                        parenthese.push_back(-1);
                        pr.push_back(i);
                    }
                }
            }
            if(pr.size() == 0){
                maxlen = i + 1;
            }else{
                maxlen = i - pr[pr.size() - 1] > maxlen ? i - pr[pr.size() - 1] : maxlen;
            }
        }
        return maxlen;
    }
};
