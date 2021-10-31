class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int maxl = INT_MIN;
        vector<int> newnum;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1) maxl = 1;
            else if(nums[i] == -1 && newnum.size() > 1 && newnum.back() == -1 && newnum[newnum.size() - 2] == -1) newnum.pop_back();
            else newnum.push_back(nums[i]);
        }
        //for(auto i : newnum) cout<<i<<' ';
        n = newnum.size();
        if(n == 0) return 1;
        else if(n == 1) return max(newnum[0], maxl);
        vector<vector<int>> OPT(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            OPT[i][i] = newnum[i];
            maxl = max(maxl, newnum[i]);
        }
        for(int i = 2; i <= n; i++){// length of subarray
            for(int j = 0; j + i - 1 < n; j++){//start point of subarray
                OPT[j][i + j - 1] = OPT[j][i + j - 2] * newnum[i + j - 1];
                maxl = max(maxl, OPT[j][i + j - 1]);
            }
        }
        return maxl;
    }
};
