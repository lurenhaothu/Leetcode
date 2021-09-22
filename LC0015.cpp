class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> numNonRep;
        vector<vector<int>> res;
        if(nums.size() < 3) return res;
        unordered_map<int, int> FreqMap;
        for(int i = 0; i < nums.size(); i++){
            if(FreqMap.find(nums[i]) == FreqMap.end()){
                numNonRep.push_back(nums[i]);
                FreqMap[nums[i]] = 1;
            }else{
                FreqMap[nums[i]]++;
            }
        }
        sort(numNonRep.begin(), numNonRep.end());
        int n = numNonRep.size();
        for(int i = 0; i < n; i++){
            FreqMap[numNonRep[i]]--;
            for(int j = i; j < n; j++){
                if(FreqMap[numNonRep[j]] == 0) continue;
                FreqMap[numNonRep[j]]--;
                int k = 0 - numNonRep[i] - numNonRep[j];
                auto iter = FreqMap.find(k);
                if(iter != FreqMap.end() && FreqMap[k] > 0 && k >= numNonRep[j]){
                    res.push_back(vector<int>{numNonRep[i], numNonRep[j], k});
                }
                FreqMap[numNonRep[j]]++;
            }
            FreqMap[numNonRep[i]]++;
        }
        return res;

    }
};
