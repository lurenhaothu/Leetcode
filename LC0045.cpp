class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> OPT(n, 0);
        for(int i = 1; i < n; i++){
            int min = n;
            for(int j = 0; j < i; j++){
                if(i - j <= nums[j]){
                    min = min < OPT[j] ? min : OPT[j];
                }
            }
            OPT[i] = min + 1;
        }
        return OPT[n - 1];
    }
};
