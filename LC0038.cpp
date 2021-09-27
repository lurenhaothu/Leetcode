class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }else{
            string s = countAndSay(n - 1);
            string res;
            char num = s[0];
            int count = 1;
            if(s.length() == 1){
                res.push_back('1');
                res.push_back(num);
                return res;
            }
            for(int i = 1; i < s.length(); i++){
                if(i < s.length() - 1){
                    if(s[i] == num){
                        count++;
                    }else{
                        res.push_back((char)(count + 48));
                        res.push_back(num);
                        num = s[i];
                        count = 1;
                    }
                }else{
                    if(s[i] == num){
                        count++;
                        res.push_back((char)(count + 48));
                        res.push_back(num);
                    }else{
                        res.push_back((char)(count + 48));
                        res.push_back(num);
                        res.push_back('1');
                        res.push_back(s[i]);
                    }
                }
            }
            return res;
        }
    }
};
