class Solution {
public:
    int trailingZeroes(int n) {
        int m = n, r = 0;
        while(m > 0){
            r += m / 5;
            m /= 5;
        }
        return r;
    }
};
