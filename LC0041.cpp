class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> dic;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) dic[nums[i]] = 1;
        }
        int res = 1;
        while(dic.find(res) != dic.end()){
            res++;
        }
        return res;
    }
};
