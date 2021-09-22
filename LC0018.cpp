class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> nrep, freq;
        vector<vector<int>> res;
        for(int i = 0; i < n; i++){
            if(i == 0){
                nrep.push_back(nums[i]);
                freq.push_back(1);
            }else if(nums[i] != nums[i - 1]){
                nrep.push_back(nums[i]);
                freq.push_back(1);
            }else{
                freq[freq.size() - 1]++;
            }
        }
        n = nrep.size();
        for(int i = 0; i < n; i++){
            freq[i]--;
            for(int j = i; j < n; j++){
                if(freq[j] == 0) continue;
                freq[j]--;
                int k = j, l = n - 1;
                while(k <= l){
                    if(freq[k] == 0){
                        k++;
                        continue;
                    }else if(k == l && freq[k] < 2){
                        break;
                    }else{
                        long long s = (long long)nrep[i] + (long long)nrep[j] + (long long)nrep[k] + (long long)nrep[l];
                        if(s == target){
                            res.push_back(vector<int>{nrep[i], nrep[j], nrep[k], nrep[l]});
                            k++;
                        }else if(s > target){
                            l--;
                        }else if(s < target){
                            k++;
                        }
                    }
                }
                freq[j]++;
            }
            freq[i]++;
        }
        return res;
    }
};
