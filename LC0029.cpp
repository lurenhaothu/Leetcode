class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned int d1, d2;
        int s1, s2;
        if(dividend < 0){
            s1 = -1;
            dividend++;
            d1 = -dividend;
            dividend--;
            d1++;
        }else if(dividend > 0){
            s1 = 1;
            d1 = dividend;
        }else{
            return 0;
        }
        if(divisor < 0){
            s2 = -1;
            divisor++;
            d2 = -divisor;
            divisor--;
            d2++;
        }else{
            s2 = 1;
            d2 = divisor;
        }
        //cout<<d1<<" "<<d2<<endl;
        unsigned int res = 0, pr = 1;
        while(d2 <= (d1 >> 1)){
            d2 = d2 << 1;
            pr = pr << 1;
        }
        while(pr >= 1){
            //cout<<pr<<" "<<d2<<" "<<res<<endl;
            if(d1 >= d2){
                d1 -= d2;
                res += pr;
            }
            pr = pr >> 1;
            d2 = d2 >> 1;
        }
        int res1;
        if(s1 * s2 > 0){
            if(res > INT_MAX){
                res1 = INT_MAX;
            }else{
                res1 = res;
            }
        }else{
            if(res > INT_MAX){
                res1 = INT_MIN;
            }else{
                res1 = -res;
            }
        }
        return res1;
    }
};
