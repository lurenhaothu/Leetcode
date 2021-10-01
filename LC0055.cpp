class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> zeroind;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) zeroind.push_back(i);
        }
        if(zeroind.size() == 0) return true;
        if(nums.size() == 1) return true;
        if(nums[0] == 0) return false;
        vector<bool> passzero(zeroind.size(), false);
        bool res = true;
        for(int i = 0; i < zeroind.size(); i++){
            for(int j = zeroind[i] - 1; j >= 0; j--){
                if(zeroind[i] - j < nums[j]){
                    passzero[i] = true;
                    break;
                }else if(zeroind[i] == nums.size() -1 && zeroind[i] - j <= nums[j]){
                    passzero[i] = true;
                    break;
                }
            }
            res = res && passzero[i];
        }
        return res;
    }
};
