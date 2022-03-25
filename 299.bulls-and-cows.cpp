/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> count_sec(10, 0), count_gue(10, 0);
        int bull = 0, cow = 0;
        for(int i = 0; i < secret.length(); i++){
            if(secret[i] == guess[i]) bull++;
            else{
                count_sec[secret[i] - '0']++;
                count_gue[guess[i] - '0']++;
            }
        }
        for(int i = 0; i < 10; i++){
            cow += min(count_sec[i], count_gue[i]);
        }
        return "" + to_string(bull) + 'A' + to_string(cow) + 'B';
    }
};
// @lc code=end

