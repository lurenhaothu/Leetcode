/*
 * @lc app=leetcode id=420 lang=java
 *
 * [420] Strong Password Checker
 */

// @lc code=start
class Solution {
    public int strongPasswordChecker(String password) {
        boolean types[] = new boolean[3];
        ArrayList<Integer> lens = new ArrayList<>();
        int length = password.length();
        int tempLen = 0;
        var str = password.toCharArray();
        for(int i = 0; i < length; i++){
            if(str[i] >= '0' && str[i] <= '9') types[0] = true;
            else if(str[i] >= 'a' && str[i] <= 'z') types[1] = true;
            else if(str[i] >= 'A' && str[i] <= 'Z') types[2] = true;
            if(i == 0 || str[i] != str[i - 1]){
                if(tempLen >= 3) lens.add(tempLen);
                tempLen = 1;
            }else{
                tempLen++;
            }
        }
        if(tempLen >= 3) lens.add(tempLen);
        int typeNum = 0;
        for(boolean t : types){
            if(t) typeNum++;
        }
        int res = 0;
        if(length < 6){
            while(length < 6){
                if(!lens.isEmpty()){
                    int len = lens.get(0);
                    if(len - 2 >= 3) lens.set(0, len - 2);
                    else lens.remove(0);
                }
                if(typeNum < 3) typeNum++;
                res++;
                length++;
            }
        }else if(length > 20){
            while(length > 20){
                if(!lens.isEmpty()){
                    boolean done = false;
                    for(int i = 0; i < lens.size(); i++){
                        int len = lens.get(i);
                        if(len % 3 == 0){
                            if(len - 1 >= 3) lens.set(i, len - 1);
                            else lens.remove(i);
                            done = true;
                            break;
                        }
                    }
                    if(!done){
                        for(int i = 0; i < lens.size(); i++){
                            int len = lens.get(i);
                            if(len % 3 == 1){
                                if(len - 1 >= 3) lens.set(i, len - 1);
                                else lens.remove(i);
                                done = true;
                                break;
                            }
                        }
                    }
                    if(!done){
                        int len = lens.get(0);
                        if(len - 1 >= 3) lens.set(0, len - 1);
                        else lens.remove(0);
                    }
                }
                res++;
                length--;
            }
        }
        while(typeNum < 3 || !lens.isEmpty()){
            if(!lens.isEmpty()){
                int len = lens.get(0);
                if(len - 3 >= 3) lens.set(0, len - 3);
                else lens.remove(0);
            }
            if(typeNum < 3) typeNum++;
            res++;
        }
        return res;
    }
}
// @lc code=end

