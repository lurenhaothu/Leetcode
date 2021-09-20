class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> DP(n, vector<int>(n, 0));
        
        //DP[i][j], i = palindrome length, j = ending point
        int Max = 0;
        string LongPal;
        int maxs;
        for(int i = 0; i < n; i++){
            DP[0][i] = 1;
        }
        //LongPal = s.substr(0, 1);
        maxs = 0;
        Max = 1;
        
        for(int i = 1; i < n; i++){
            DP[1][i] = (s[i] == s[i - 1]);
            if(DP[1][i] == 1){
                Max = 2;
                //LongPal = s.substr(i-1, 2);
                maxs = i - 1;
            }
        }
        for(int i = 2; i < n; i++){
            if(i + 1 > Max + 2) break;
            for(int j = i; j < n; j++){
                DP[i][j] = (s[j] == s[j - i]) && DP[i - 2][j - 1];
                if(DP[i][j] == 1){
                    Max = i + 1;
                    //LongPal = s.substr(j - i, i + 1);
                    maxs = j - i;
                }
            }
        }
        return s.substr(maxs, Max);
    }
};
