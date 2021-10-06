class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tmap, dic;
        for(int i = 0; i < t.length(); i++){
            dic[t[i]] = 0;
            if(tmap.find(t[i]) == tmap.end()) tmap[t[i]] = 1;
            else tmap[t[i]]++;
        }
        int validLength = 0;
        int start = 0, end;
        int shortLength, bestStart, bestEnd;
        while(start < s.length()){
            if(dic.find(s[start]) != dic.end()) break;
            else start++;
            if(start == s.length()) return string("");
        }
        dic[s[start]]++;
        validLength = 1;
        if(validLength == t.length()) return string({s[start]});
        for(end = start + 1; end < s.length(); end++){
            if(dic.find(s[end]) != dic.end()){
                dic[s[end]]++;
                if(dic[s[end]] <= tmap[s[end]]) validLength++;
            }
            if(validLength == t.length()) break;
        }
        for(; start < end; start++){
            if(dic.find(s[start]) != dic.end()){
                if(dic[s[start]] - 1 >= tmap[s[start]]){
                    dic[s[start]]--;
                }else{
                    break;
                }
            }
        }
        if(validLength != t.length()) return string("");
        shortLength = end - start + 1;
        bestStart = start;
        bestEnd = end;
        while(1){
            if(end == s.length() - 1) break;
            for(end = end + 1; end < s.length(); end++){
                if(dic.find(s[end]) != dic.end()){
                    dic[s[end]]++;
                }
                if(s[end] == s[start]) break;
            }
            if(end == s.length()) break;
            for(; start < end; start++){
                if(dic.find(s[start]) != dic.end()){
                    if(dic[s[start]] - 1 >= tmap[s[start]]){
                        dic[s[start]]--;
                    }else{
                        break;
                    }
                }
            }
            if(end - start + 1 < shortLength){
                shortLength = end - start + 1;
                bestStart = start;
                bestEnd = end;
            }
            //if(end == s.length() - 1) break;
        }
        return s.substr(bestStart, shortLength);
    }
};
