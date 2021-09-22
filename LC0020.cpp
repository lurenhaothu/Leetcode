class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, int> dic{{'(', 1}, {')',11}, {'[',2}, {']',12}, {'{',3}, {'}',13}};
        vector<int> stack;
        for(int i = 0; i < s.length(); i++){
            if(stack.size() == 0){
                if(dic[s[i]] > 9) return false;
                stack.push_back(dic[s[i]]);
            }else{
                if(dic[s[i]] < 9) stack.push_back(dic[s[i]]);
                else{
                    if(stack[stack.size() - 1] + 10 == dic[s[i]]) stack.pop_back();
                    else return false;
                }
            }
        }
        if (stack.size() == 0) return true;
        else return false;
    }
};
