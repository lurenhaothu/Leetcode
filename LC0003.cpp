class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //slicing window
        int start = 0, end = 0;
        unordered_map<char, int> charmap;
        if(s.length() == 0) return 0;
        //charmap[s[0]] = 0;
        int MaxLen = 0;
        int L = s.length();
        for(int i = 0; i < L; i++){
            end = i;
            if(charmap.find(s[end]) == charmap.end()){
                charmap[s[end]] = end;
            }else{
                for(int j = start; j < charmap[s[end]]; j++) charmap.erase(s[j]);
                start = charmap[s[end]] + 1;
                charmap[s[end]] = end;
            }
            MaxLen = (end - start) > MaxLen ? (end - start) : MaxLen;
            cout<<start<<end<<endl;
        }
        return MaxLen + 1;
    }
};
