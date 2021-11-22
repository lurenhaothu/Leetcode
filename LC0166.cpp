class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long int n = numerator, d = denominator;
        string R;
        bool neg = false;
        if(n == 0) return "0";
        else if(n > 0 && d < 0){
            d  = -d;
            neg = true;
        }else if(n < 0 && d > 0){
            n = -n;
            neg = true;
        }else if(n < 0 && d < 0){
            n = -n;
            d = -d;
        }
        long long int Npart = n / d, Left = n % d;
        while(Npart != 0){
            R.insert(R.begin(), Npart % 10 + 48);
            Npart /= 10;
        }
        if(R.length() == 0) R.insert(R.begin(), '0');
        if(neg) R.insert(R.begin(), '-');
        if(Left == 0) return R;
        R.insert(R.end(), '.');
        unordered_map<int, int> dic;
        int pr = R.length();
        while(Left != 0){
            if(dic.find(Left) != dic.end()){
                R.insert(R.begin() + dic[Left], '(');
                R.insert(R.end(), ')');
                return R;
            }
            dic[Left] = pr;
            R.insert(R.end(), Left * 10 / d + 48);
            pr++;
            Left = Left * 10 % d;
        }
        return R;
    }
};
