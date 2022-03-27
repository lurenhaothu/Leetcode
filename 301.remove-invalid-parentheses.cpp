/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        stack<int> st;
        vector<int> delright, delleft;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                }else{
                    //now we need to delete one ) before i
                    delright.push_back(i);
                }
            } 
        }
        while(!st.empty()){
            delleft.push_back(st.top());
            st.pop();
        }
        //for(auto i : delright) cout<<i;
        unordered_set<string> res;
        DFS(s, delright, delleft, 0, 0, res);
        vector<string> r(res.begin(), res.end());
        return r;
    }
    void DFS(string& s, vector<int>& delright, vector<int>& delleft, 
             int flag, int index, unordered_set<string>& res){
        if(flag == 0){
            //del rights
            if(index >= delright.size()) DFS(s, delright, delleft, 1, 0, res);
            else{
                for(int i = 0; i <= delright[index]; i++){
                    if(s[i] == ')'){
                        s[i] = '!';
                        DFS(s, delright, delleft, 0, index + 1, res);
                        s[i] = ')';
                    }
                }
            }
        }else{
            if(index >= delleft.size()) helper(s, res);
            else{
                for(int i = delleft[index]; i < s.length(); i++){
                    if(s[i] == '('){
                        s[i] = '!';
                        DFS(s, delright, delleft, 1, index + 1, res);
                        s[i] = '(';
                    }
                }
            }
        }
    }
    void helper(string& s, unordered_set<string>& res){
        //cout<<s;
        string r;
        for(auto i : s){
            if(i != '!') r += i;
        }
        res.insert(r);
    }
};
// @lc code=end

