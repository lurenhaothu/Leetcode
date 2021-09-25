class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;
        int pr = nums.size() - 1, i, j, s;
        while(pr > 0){
            if(nums[pr - 1] < nums[pr]){
                break;
            }else{
                pr--;
            }
        }
        if(pr == 0 && nums[0] >= nums[1]){
            pr = 0;
            i = 0;
            j = nums.size() - 1;
            while(i < j){
                s = nums[i];
                nums[i] = nums[j];
                nums[j] = s;
                i++;
                j--;
            }
            return;
        }else if(pr == 0 && nums[0] < nums[1]){
            pr = 1;
        }
        int NextMax = pr;
        for(int k = pr; k < nums.size(); k++){
            if(nums[k] > nums[pr - 1]){
                NextMax = nums[NextMax] < nums[k] ? NextMax : k;
            }
        }
        s = nums[pr - 1];
        nums[pr - 1] = nums[NextMax];
        nums[NextMax] = s;
        i = pr;
        j = nums.size() - 1;
        while(i < j){
            s = nums[i];
            nums[i] = nums[j];
            nums[j] = s;
            i++;
            j--;
        }
        cout<<NextMax;
        return;
    }
};
