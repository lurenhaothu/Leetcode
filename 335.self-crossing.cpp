/*
 * @lc app=leetcode id=335 lang=cpp
 *
 * [335] Self Crossing
 */

// @lc code=start
class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int n = distance.size();
        if(n <= 3) return false;
        if(distance[0] >= distance[2]){
            //getting smaller mode
            int right = 0;
            int left = -distance[1];
            int top = distance[0];
            int bot = distance[0] - distance[2];
            for(int i = 3; i < n; i++){
                int dir = i % 4;
                switch(dir){
                    case 0:
                        if(distance[i] + bot >= top) return true;
                        else top = distance[i] + bot;
                        break;
                    case 1:
                        if(right - distance[i] <= left) return true;
                        else left = right - distance[i];
                        break;
                    case 3:
                        if(distance[i] + left >= right) return true;
                        else right = distance[i] + left;
                        break;
                    case 2:
                        if(top - distance[i] <= bot) return true;
                        else bot = top - distance[i];
                        break;
                }
            }
            return false;
        }else{
            //getting larger mode
            int right = 0;
            int oldright, oldleft = 0, oldtop, oldbot = 0;
            int left = -distance[1];
            int top = distance[0];
            int bot = distance[0] - distance[2];
            int flag = 0;//free
            for(int i = 3; i < n; i++){
                int dir = i % 4;
                if(flag == 0){
                    switch(dir){
                        case 0:
                            if(distance[i] + bot <= top) {flag = 1;top = distance[i] + bot;if(top >= oldbot) left = oldright;}
                            else {oldtop = top; top = distance[i] + bot;}
                            break;
                        case 1:
                            if(right - distance[i] >= left) {flag = 1;left = right - distance[i];if(left <= oldright) bot = oldtop;}
                            else {oldleft = left; left = right - distance[i];}
                            break;
                        case 3:
                            if(distance[i] + left <= right){flag = 1;right = distance[i] + left;if(right >= oldleft) top = oldbot; }
                            else {oldright = right; right = distance[i] + left;}
                            break;
                        case 2:
                            if(top - distance[i] >= bot){flag = 1; bot = top - distance[i];if(bot <= oldtop)right = oldleft;}
                            else {oldbot = bot; bot = top - distance[i];}
                            break;
                    }
                }else{
                    switch(dir){
                        case 0:
                            if(distance[i] + bot >= top) return true;
                            else top = distance[i] + bot;
                            break;
                        case 1:
                            if(right - distance[i] <= left) return true;
                            else left = right - distance[i];
                            break;
                        case 3:
                            if(distance[i] + left >= right) return true;
                            else right = distance[i] + left;
                            break;
                        case 2:
                            if(top - distance[i] <= bot) return true;
                            else bot = top - distance[i];
                            break;
                    }
                }
            }
            return false;
        }
        return true;
    }
};
// @lc code=end

