/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        int n = envelopes.size();
        vector<int> vect;
        stack<vector<int>> st;
        for(int i = 0; i < n; i++){
            if(!st.empty() && st.top()[0] != envelopes[i][0]){
                while(!st.empty()){
                    vect.push_back(st.top()[1]);
                    st.pop();
                }
            }
            st.push(envelopes[i]);
        }
        while(!st.empty()){
            vect.push_back(st.top()[1]);
            st.pop();
        }
        //for(auto i : vect) cout<<i<<' ';cout<<endl;
        return helper(vect);
    }
    int helper(vector<int> &vect){
        vector<int> sub;
        for(auto i : vect){
            if(sub.empty() || sub.back() < i) sub.push_back(i);
            else update(sub, i);
            //for(auto j : sub) cout<<j<<' ';
            //cout<<endl;
        }
        return sub.size();
    }
    void update(vector<int> & vect, int i){
        int start = 0, end = vect.size() - 1;
        int pivot;
        while(start < end){
            pivot = (start + end) / 2;
            if(vect[pivot] < i){
                start = pivot + 1;
            }else if(vect[pivot] > i){
                end = pivot;
            }else{
                return;
            }
        }
        vect[start] = i;
        return;
    }
};
// @lc code=end

