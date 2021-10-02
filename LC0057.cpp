class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0) return vector<vector<int>>{newInterval};
        //if(newInterval[0] == newInterval[1]) return intervals;
        
        
        vector<vector<int>> res;
        int index;
        bool inserted = false;
        if(newInterval[0] < intervals[0][0]){
            res.push_back(newInterval);
            index = 0;
            inserted = true;
        }else{
            res.push_back(intervals[0]);
            index = 1;
        }
        while(index < intervals.size() || (!inserted)){
            vector<int> push;
            if(!inserted){
                if(index == intervals.size()){//newInterval[0] >= res.back()[0])
                    push = newInterval;
                    inserted = true;
                }else if(newInterval[0] >= res.back()[0] && newInterval[0] < intervals[index][0]){
                    push = newInterval;
                    inserted = true;
                }else{
                    push = intervals[index];
                    index++;
                }
            }else{
                push = intervals[index];
                index++;
            }
            if(res.back()[1] < push[0]){
                res.push_back(push);
            }else{
                if(res.back()[1] < push[1]){
                    res.back()[1] = push[1];
                }
            }
        }
        return res;
    }
};
