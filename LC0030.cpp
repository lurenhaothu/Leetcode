class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int l = s.length();
        int n = words.size(), subl = words[0].length();
        unordered_map<string, int> dic, ref;
        for(auto& w : words){
            dic.insert({w, 0});
            if(ref.find(w) == ref.end()){
                ref.insert({w, 1});
            }else{
                ref[w]++;
            }
        }
        for(int i = 0; i <= l - n * subl; i++){
            for(int j = 0; j < n; j++){
                string k = s.substr(i + j * subl, subl);
                if(dic.find(k) != dic.end()){
                    if(dic[k] < ref[k]){
                        dic[k]++;
                    }else{
                        break;
                    }
                }else{
                    break;
                }
                if(j == n - 1) res.push_back(i);
            }
            for(auto &d : dic) d.second = 0;
        }
        return res;
    }
};
