/*
 * @lc app=leetcode id=352 lang=cpp
 *
 * [352] Data Stream as Disjoint Intervals
 */

// @lc code=start
class SummaryRanges {
    map<int, int> dict;
    //second: 0: left and right, 1: left, 2: right;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        if(dict.empty()){dict[val] = 0;return;}
        auto itr = dict.lower_bound(val);
        if(itr == dict.begin()){
            if(itr->first == val) return;
            else if(itr->first == val + 1){
                if(itr->second == 1){
                    //itr->first--;
                    int key = itr->first;
                    dict[key - 1] = 1;
                    dict.erase(key);
                    return;
                }else if(itr->second == 0){
                    //itr->second = 2;
                    //dict.insert(make_pair(val, 1));
                    int key = itr->first;
                    dict[key] = 2;
                    dict[val] = 1;
                }
            }else{
                //dict.insert(make_pair(val, 0));
                dict[val] = 0;
            }
        }else if(itr == dict.end()){
            itr--;
            if(itr->first == val) return;
            else if(itr->first == val - 1){
                if(itr->second == 2){
                    //itr->first++;
                    int key = itr->first;
                    dict[key + 1] = 2;
                    dict.erase(key);
                    return;
                }else if(itr->second == 0){
                    //itr->second = 1;
                    //dict.insert(make_pair(val, 2));
                    int key = itr->first;
                    dict[key] = 1;
                    dict[key + 1] = 2;
                }
            }else{
                //dict.insert(make_pair(val, 0));
                dict[val] = 0;
            }
        }else{
            auto itr2 = itr;
            itr--;
            int key1 = itr->first;
            int key2 = itr2->first;
            if(itr2->second == 2) return;
            else if(itr2->first == val) return;
            else if(itr2->first == val + 1 && itr->first == val - 1){
                if(itr2->second == 1){
                    if(itr->second == 2){
                        dict.erase(key1);
                        dict.erase(key2);
                    }else if(itr->second == 0){
                        //itr->second = 1;
                        dict[key1] = 1;
                        dict.erase(key2);
                    }
                }else if(itr2->second == 0){
                    if(itr->second == 2){
                        dict.erase(key1);
                        //itr2->second = 2;
                        dict[key2] = 2;
                    }else if(itr->second == 0){
                        //itr->second = 1;
                        //itr2->second = 2;
                        dict[key1] = 1;
                        dict[key2] = 2;
                    }
                }
            }else if(itr2->first == val + 1){
                if(itr2->second == 1){
                    //itr2->first--;
                    dict[val] = 1;
                    dict.erase(key2);
                    return;
                }else if(itr2->second == 0){
                    //itr2->second = 2;
                    //dict.insert(make_pair(val, 1));
                    dict[val] = 1;
                    dict[key2] = 2;
                }
            }else if(itr->first == val - 1){
                if(itr->second == 2){
                    //itr->first++;
                    dict[val] = 2;
                    dict.erase(key1);
                    return;
                }else if(itr->second == 0){
                    //itr->second = 1;
                    //dict.insert(make_pair(val, 2));
                    dict[val] = 2;
                    dict[key1] = 1;
                }
            }else{
                //dict.insert(make_pair(val, 0));
                dict[val] = 0;
            }
        }
        
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for(auto i : dict){
            if(i.second == 0) res.push_back({i.first, i.first});
            else if(i.second == 1) res.push_back({i.first});
            else res.back().push_back(i.first);
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end

