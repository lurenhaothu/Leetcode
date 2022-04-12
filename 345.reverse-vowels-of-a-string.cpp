/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        int start = 0, end = s.length() - 1;
        while(start < s.length() && !isVowel(s[start])) start++;
        while(end >= 0 && !isVowel(s[end])) end--;
        while(start < end){
            swap(s[start], s[end]);
            start++;
            end--;
            while(start < s.length() && !isVowel(s[start])) start++;
            while(end >= 0 && !isVowel(s[end])) end--;
        }
        return s;
    }
    bool isVowel(char c){
        switch(c){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                return true;
            default:
                return false;
        }
    }
};
// @lc code=end

