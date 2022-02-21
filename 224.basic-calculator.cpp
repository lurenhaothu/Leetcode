/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        stack<vector<int>> st;
        //{type, val} in st
        //type 0, number
        //type 1,2,3,4: + - ( )
        int flag = 1;
        int newnumber = 1;
        int r;
        for(auto itr = s.begin(); itr != s.end(); itr++){
            char c = *itr;
            if(c >= '0' && c <= '9'){
                if(newnumber == 0){
                    st.top().back() *= 10;
                    st.top().back() += flag * (c - '0');
                }else if(newnumber == 1){
                    st.push({0, flag * (c - '0')});
                    newnumber = 0;
                }
            }
            else{
                switch(c){
                case '+':
                    //st.push({1, 0});
                    flag = 1;
                    break;
                case '-':
                    //st.push({2, 0});
                    flag = -1;
                    break;
                case '(':
                    st.push({3, flag});
                    flag = 1;
                    break;
                case ')':
                    //complicated part
                    r = 0;
                    while(st.top()[0] != 3){
                        r += st.top()[1];
                        st.pop();
                    }
                    r *= st.top()[1];
                    st.pop();
                    st.push({0, r});
                    flag = 1;
                    break;
                case ' ':
                default:
                    break;
                }
                newnumber = 1;
            }
        }
        r = 0;
        while(!st.empty()){
            r += st.top()[1];
            st.pop();
        }
        return r;
    }
    
};
//"1+2-123+(2+3+(1-2))"\n
//"- (3 + (4 + 5))"\n
// @lc code=end

