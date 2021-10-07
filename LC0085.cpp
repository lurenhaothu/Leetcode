class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        vector<int> heights(matrix[0].size(), 0);
        int res = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < heights.size(); j++){
                if(matrix[i][j] == '0') heights[j] = 0;
                else heights[j]++;
            }
            res = max(res, largestRectangleArea(heights));
        }
        return res;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        stack<int> monotonicStack;
        int res = 0;
        heights.push_back(0);
        //heights.insert(heights.begin(), 0);
        for(int i = 0; i < heights.size(); i++){
            while(monotonicStack.size() != 0 && heights[i] < heights[monotonicStack.top()]){
                int h = heights[monotonicStack.top()];
                monotonicStack.pop();
                if(monotonicStack.size() == 0){
                    res = max(res, h * i);
                }
                else res = max(res, h * (i - monotonicStack.top() - 1));
            }
            monotonicStack.push(i);
            //cout<<monotonicStack.size();
        }
        heights.pop_back();
        return res;
    }
};
