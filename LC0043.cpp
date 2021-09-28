class Solution {
public:
    string multiply(string num1, string num2) { // divide and conquer
        string result;
        while(num1[0] == '0'){
            num1.erase(num1.begin());
        }
        while(num2[0] == '0'){
            num2.erase(num2.begin());
        }
        int n1 = num1.length(), n2 = num2.length();
        if(n1 == 1 && n2 == 1){
            int res = ((int)num1[0] - 48) * ((int)num2[0] - 48);
            string r;
            while(res > 0){
                r = (char)(res % 10 + 48) + r;
                res /= 10;
            }
            result = r;
        }else if(n1 == 0 || n2 == 0){
            string r;
            result = r;
        }else{
            int maxlen = n1 > n2 ? n1 : n2;
            int sep = maxlen / 2;
            string num11, num12, num21, num22;
            if(n1 - maxlen / 2 - 1 < 0){
                num12 = num1;
            }else{
                num11 = num1.substr(0, n1 - maxlen / 2);
                num12 = num1.substr(n1 - maxlen / 2, maxlen / 2);
            }
            if(n2 - maxlen / 2 - 1 < 0){
                num22 = num2;
            }else{
                num21 = num2.substr(0, n2 - maxlen / 2);
                num22 = num2.substr(n2 - maxlen / 2, maxlen / 2);
            }
            string r1, r2, r3, r4;
            r1 = multiply(num11, num21);
            r2 = multiply(num11, num22);
            r3 = multiply(num12, num21);
            r4 = multiply(num12, num22);
            string zeros(maxlen / 2, '0');
            r1 = r1 + zeros + zeros;
            r2 = r2 + zeros;
            r3 = r3 + zeros;
            string res = sum(sum(r1, r2), sum(r3, r4));
             result = res;
        }
        if(result.length() == 0){
            result = result + '0';
        }
        return result;
    }
    string sum(string num1, string num2){
        string res;
        while(num1[0] == '0'){
            num1.erase(num1.begin());
        }
        while(num2[0] == '0'){
            num2.erase(num2.begin());
        }
        int n1 = num1.length(), n2 = num2.length();
        int maxlen = n1 > n2 ? n1 : n2;
        int carry = 0, sum = 0;
        for(int i = 0; i < maxlen; i++){
            sum += carry;
            if(n1 - 1 - i >= 0){
                sum += (int)(num1[n1 - 1 - i]) - 48;
            }
            if(n2 - 1 - i >= 0){
                sum += (int)(num2[n2 - 1 - i]) -48;
            }
            carry = sum / 10;
            sum = sum % 10;
            res = (char)(sum + 48) + res;
            sum = 0;
        }
        if(carry != 0){
            res = '1' + res;
        }
        return res;
    }
};
