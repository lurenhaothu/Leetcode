class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factor;
        string res;
        factor.push_back(1);
        for(int i = 2; i <= n - 1; i++) factor.push_back(factor.back() * i);
        string candidate;
        for(int i = 1; i <= n; i++) candidate.push_back((char)(i + 48));
        int index;
        k = k - 1;
        for(int i = n - 2; i >= 0; i--){
            index = k / factor[i];
            res.push_back(candidate[index]);
            candidate.erase(candidate.begin() + index);
            k = k % factor[i];
        }
        res.push_back(candidate[0]);
        return res;
    }
};
