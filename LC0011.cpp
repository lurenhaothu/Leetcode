class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int res = (right - left) * min(height[left], height[right]);
        while(left < right){
            if(height[left] < height[right]){
                left++;
                res = max(res, (right - left) * min(height[left], height[right]));
            }else{
                right--;
                res = max(res, (right - left) * min(height[left], height[right]));
            }
        }
        return res;
    }
};
