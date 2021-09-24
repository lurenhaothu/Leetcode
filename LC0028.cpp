class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0) return 0;
        int lh = haystack.length(), ln = needle.length();
        if(ln > lh) return -1;
        for(int i = 0; i < lh - ln + 1; i++){
            if(needle == haystack.substr(i, ln)) return i;
            //cout<<haystack.substr(i, ln)<<endl;
        }
        return -1;
    }
};
