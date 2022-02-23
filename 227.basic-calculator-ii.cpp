/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
#include <stack>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        stack<vector<int>> st;
        //{op, num}, op 0: num
        //op 1: +, op 2: - 3: *, 4: /
        int sign = 1;
        int temp;
        s = s + '+';
        for(auto i : s){
            if(i >= '0' && i <= '9'){
                if(st.empty() || st.top()[0] != 0){
                    st.push({0, sign * (i - '0')});
                }else{
                    st.top()[1] *= 10;
                    st.top()[1] += sign * (i - '0');
                }
                continue;
            }else if(i == '+' || i == '-' || i == '*' || i == '/'){
                if(st.size() >= 3){
                    int num1 = st.top()[1];
                    st.pop();
                    int op = st.top()[0];
                    if(op == 1){
                        st.push({0, num1});
                    }else{
                        st.pop();
                        int num2 = st.top()[1];
                        st.pop();
                        if(op == 3) st.push({0, num1 * num2});
                        else if(op == 4) st.push({0, num2 / num1});
                    }
                } 
            }
            switch(i){
            case '+':
                sign = 1;
                st.push({1, 0});
                break;
            case '-':
                sign = -1;
                if(!st.empty()) st.push({1, 0});
                break;
            case '*':
                sign = 1;
                st.push({3, 0});
                break;
            case '/':
                sign = 1;
                st.push({4, 0});
                break;
            case ' ':
            default:
                break;
            }
        }
        st.pop();
        int res = st.top()[1];
        st.pop();
        while(!st.empty()){
            if(st.top()[0] == 0) res += st.top()[1];
            st.pop();
        }
        return res;
    }
};
// @lc code=end

