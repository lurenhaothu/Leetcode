class Solution {
public:
    string convertToTitle(int columnNumber) {
        string r;
        int c = columnNumber;
        while(c != 0){
            if(c % 26 == 0){
                r.insert(r.begin(), 'Z');
                c -= 26;
            }else{
                r.insert(r.begin(), c % 26 + 64);
            }
            c /= 26;
        }
        return r;
    }
};
