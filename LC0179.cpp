class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> n;
        for(int i = 0; i < nums.size(); i++){
            n.push_back(to_string(nums[i]));
        }
        sort(n.begin(), n.end(), myfunction);
        string r;
        for(int i = 0; i < nums.size(); i++){
            r.append(n[i]);
        }
        while(r[0] == '0'){
            r.erase(r.begin());
        }
        if(r.length() == 0) r = r + "0";
        return r;
    }
    
    static bool myfunction (string i,string j) {
        string a = i + j, b = j + i;
        for(int i = 0; i < a.length(); i++){
            if(a[i] == b[i]) continue;
            else return a[i] > b[i];
        }
        return false;
    }
};
