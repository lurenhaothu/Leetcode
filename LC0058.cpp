class Solution {
public:
    int lengthOfLastWord(string s) {
        int start, end;
        end = s.length() - 1;
        while(s[end] == ' ') end--;
        start = end;
        while(start >= 0){
            if(s[start] == ' ') break;
            start--;
        }
        //if(start == -1) return end - start + 1;
        return end - start;
    }
};
