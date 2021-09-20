class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> num1 = nums;
        sort(num1.begin(), num1.end());
        vector<int> num2 = num1;
        for(int i = 0; i < num1.size(); i++){
            num2[i] = target - num1[i];
        }
        
        int num1point = 0, num2point = num2.size() - 1;
        while(num1point != num1.size() && num2point != -1){
            if(num1[num1point] == num2[num2point]) break;
            else if(num1[num1point] > num2[num2point]) num2point--;
            else if(num1[num1point] < num2[num2point]) num1point++;
        }
        
        int a = -1, b = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == num1[num1point]) a = i;
            if(nums[i] == num1[num2point]) b = i;
        }
        if(a == b){
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == num1[num2point]){
                    a = i;
                    break;
                }
            }
        }
                                         
        return vector<int> {a,b};
    } 
};
