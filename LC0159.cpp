class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        if(n <= 2) return n;
        auto itr1 = s.begin(), itr2 = s.begin() + 1;
        unordered_map<char, int> dic;
        dic[*itr1] = 1;
        int disnum = 1;
        int maxlen = 2;
        while(itr1 != s.end()){
            //cout<<*itr1<<*itr2<<disnum<<(int)distance(itr1, itr2)<<endl;
            if(disnum <= 2){
                maxlen = max(maxlen, (int)distance(itr1, itr2));
                if(itr2 == s.end()) return maxlen;
                if(dic[*itr2]++ == 0){
                    assert(dic[*itr2] == 1);
                    disnum++;
                }
                itr2++;
                continue;
            }else{
                if(--dic[*itr1] == 0) disnum--;
                itr1++;
                continue;
            }
        }
        return maxlen;
    }
};
