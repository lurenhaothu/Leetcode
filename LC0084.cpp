class Solution {
public:
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
        return res;
    }
};
