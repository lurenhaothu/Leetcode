class Solution {
public:
    double myPow(double x, int n) {
        double cur = x, res = 1;
        unsigned int pow;
        if(x == 0) return 0;
        if(n < 0){
            cur = 1 / x;
            pow = (unsigned int)(-(n + 1)) + 1;
        }else if(n == 0){
            return 1;
        }else{
            pow = n;
        }
        while(pow != 0){
            if(1&pow) res *= cur;
            pow = pow >> 1;
            cur = cur * cur;
        }
        return res;
    }
};
