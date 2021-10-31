class Solution {
public:
    string reverseWords(string s) {
        int l = s.length();
        int p1 = 0, p2;
        string res;
        do{
            while(p1 < l && s[p1] == ' ') p1++;
            if(p1 == l) break;
            p2 = p1;
            while(p2 < l && s[p2] != ' ') p2++;
            res = s.substr(p1, p2 - p1) + ' ' + res;
            //cout<<p1<<' '<<p2<<' '<<res<<endl;
            p1 = p2;
        }while(p1 < l);
        res.erase(res.end() - 1);
        return res;
    }
};
