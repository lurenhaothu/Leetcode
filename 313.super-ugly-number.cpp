/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 */

// @lc code=start
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly = {1};
        multimap<int, int> dict;
        for(auto i : primes) dict.insert(make_pair(i, 0)); //the value is the ptr in ugly
        for(int i = 1; i < n; i++){
            auto itr = dict.begin();
            int uglynum = itr->first;
            int ptr = itr->second;
            int prime = uglynum / ugly[ptr];
            ugly.push_back(uglynum);
            dict.erase(itr);
            if((long long)prime * ugly[ptr + 1] <= INT_MAX) dict.insert(make_pair(prime * ugly[ptr + 1], ptr + 1));
            while(dict.begin()->first == uglynum){
                int nextptr = dict.begin()->second;
                int nextprime = dict.begin()->first / ugly[nextptr];
                dict.erase(dict.begin());
                if((long long)nextprime * ugly[nextptr + 1] <= INT_MAX) dict.insert(make_pair(nextprime * ugly[nextptr + 1], nextptr + 1));
            }
        }
        //for(auto i : ugly) cout<<i<<' ';
        return ugly.back();
    }
};
// @lc code=end

