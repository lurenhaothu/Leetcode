class Solution {
public:
    string intToRoman(int num) {
        int num1[4], n = num;
        for(int i = 3; i >= 0; i--){
            num1[i] = n % 10;
            n /= 10;
        }
        
        vector<string> ROMAN1 {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        vector<string> ROMAN2 {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        vector<string> ROMAN3 {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        vector<string> ROMAN4 {"","M","MM","MMM"};
        return ROMAN4[num1[0]]+ROMAN3[num1[1]]+ROMAN2[num1[2]]+ROMAN1[num1[3]];
        
    }
};
