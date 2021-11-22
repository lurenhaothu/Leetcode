class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l1 = version1.length(), l2 = version2.length();
        int pr1 = 0, pr2 = 0;
        while(pr1 < l1 || pr2 < l2){
            //if(pr1 == l1 && pr2 < l2) return -1;
            //else if(pr1 < l1 && pr2 == l2) return 1;
            if(pr1 == l1 && pr2 == l2) return 0;
            int num1 = 0, num2 = 0;
            if(pr1 != l1){
                for(;pr1 < l1 && version1[pr1] != '.'; pr1++){
                    num1 = num1 * 10 + (version1[pr1] - 48);
                }
            }
            if(pr1 < l1) pr1++;
            if(pr2 != l2){
                for(;pr2 < l2 && version2[pr2] != '.'; pr2++){
                    num2 = num2 * 10 + (version2[pr2] - 48);
                }
            }
            if(pr2 < l2) pr2++;
            //cout<<num1<<num2<<endl;
            if(num1 > num2) return 1;
            else if(num1 < num2) return -1;
        }
        return 0;
    }
};
