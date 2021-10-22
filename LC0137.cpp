class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0,carry = 0,c = 0;
        for(int i : nums){
            carry += sum & i;
            sum = sum ^ i;
            c = sum & carry;
            sum = sum & (~c);
            carry = carry & (~c);
            //cout<<sum<<' '<<carry<<endl;
        }
        return sum;
    }
};
