class Solution {
public:
    string addBinary(string a, string b) {
        int l = max(a.length(), b.length());
        string res(l, '0');
        int r = 0, carry = 0;
        for(int i = l - 1; i >= 0; i--){
            r = carry;
            if(a.length() - l + i >= 0 && a.length() - l + i < a.length()){
                r += (int)(a[a.length() - l + i] == '1'); 
            }
            //cout<<b.length() - l + i<<endl;
            if(b.length() - l + i >= 0 && b.length() - l + i < b.length()){
                r += (int)(b[b.length() - l + i] == '1'); 
            }
            carry = r / 2;
            res[i] = (r % 2) ? '1' : '0';
        }
        if(carry) res.insert(res.begin(),'1');
        return res;
    }
};
