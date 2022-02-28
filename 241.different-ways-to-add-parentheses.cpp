/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> nums;
        vector<char> ops;
        bool newnum = true;
        for(auto i : expression){
            if(i >= '0' && i <= '9'){
                if(newnum){
                    nums.push_back(i - '0');
                    newnum = false;
                }else{
                    nums.back() = nums.back() * 10 + i - '0';
                }
            }else{
                ops.push_back(i);
                newnum = true;
            }
        }
        int n = nums.size(); //n is the number of numbers;
        vector<vector<multiset<int>>> DP(n, vector<multiset<int>>(n, multiset<int>{}));
        for(int i = 0; i < n; i++){
            DP[i][i].insert(nums[i]);
        }
        //dp[i][j] is all possible results from i to j, inclusively
        for(int i = 2; i <= n; i++){ // i is the length of the expression
            for(int j = 0; i + j - 1 < n; j++){ // j is the start of the op
                multiset<int> &curdic = DP[j][i + j - 1];
                for(int k = j; k < i + j - 1; k++){
                    // calculating j ~ k and k + 1 ~ i + j - 1
                    for(auto num1 : DP[j][k]){
                        for(auto num2 : DP[k + 1][i + j - 1]){
                            curdic.insert(calculate(num1, num2, ops[k]));
                        }
                    }
                }
            }
        }
        vector<int> res (DP[0][n - 1].begin(), DP[0][n - 1].end());
        return res;
    }
    int calculate(int a, int b, char op){
        switch(op){
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
        }
        return 0;
    }
};
// @lc code=end

