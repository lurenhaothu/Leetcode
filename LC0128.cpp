class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int maxSize = 1;
        unordered_map<int, int> dic;
        for(int i = 0; i < nums.size(); i++){
            if(dic.find(nums[i]) == dic.end()){
                dic[nums[i]] = 1;
            }
        }
        for(auto it = dic.begin(); it != dic.end(); it++){
            if(dic.find(it->first - 1) == dic.end()){
                continue;
            }
            int cur = it->first;
            while(dic.find(cur - 1) != dic.end()){
                cur = cur - 1;
                it->second += dic[cur];
                dic.erase(cur);
            }
            maxSize = max(maxSize, it->second);
        }
        return maxSize;
    }
};
