class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int minigas = INT_MAX, minindex, sum = 0;
        for(int i = 0; i < n; i++){
            sum = sum + gas[i] - cost[i];
            if(minigas > sum){
                minigas = sum;
                minindex = i;
            }
        }
        if(sum < 0) return -1;
        if(minindex == n - 1) minindex = 0;
        else minindex++;
        return minindex;
    }
};
