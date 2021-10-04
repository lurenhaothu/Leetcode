class Solution {
public:
    int mySqrt(int x) {
        long long res = 0, op = 1;
        do{
            op = 1;
            while((res + op) * (res + op) <= x){
                op = op << 1;
            }
            res += (op >> 1);
            //cout<< op;
        }while(op != 1);
        return res;
    }
};
