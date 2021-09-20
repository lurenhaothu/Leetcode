class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        vector<int> num;
        int n = x;
        while(n > 0){
            num.push_back(n%10);
            n /= 10;
        }
        for(int i = 0; i < num.size() / 2; i++){
            if(num[i] != num[num.size() - i - 1]) return false;
        }
        return true;
    }
};
