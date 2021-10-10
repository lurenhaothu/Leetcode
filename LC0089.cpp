class Solution {
public:
    vector<int> grayCode(int n) {
        vector<bool> found(pow(2, n), false);
        vector<int> res;
        res.push_back(0);
        found[0] = true;
        DFS(res, found, n);
        return res;
    }
    
    bool DFS(vector<int>& res, vector<bool>& found, int n){
        if(res.size() == pow(2, n)){
            //for(int i = 0; i < res.size(); i++)cout<<res[i];
            //cout<<endl;
            if(res.back() == 0) return false;
            else if((res.back() & (res.back() - 1)) == 0) return true;
            else return false;
        }
        //cout<<res.back()<<endl;
        for(int i = 0; i < n; i++){
            if(res.back() & (1<<i)){
                int t = res.back() & ~(1<<i);
                //cout<<t;
                if(!found[t]){
                    res.push_back(t);
                    found[res.back()] = true;
                    if(DFS(res, found, n)) return true;
                    found[res.back()] = false;
                    res.pop_back();
               }
            }else{
                int t = res.back() | (1<<i);
                //cout<<t;
                if(!found[t]){
                    res.push_back(t);
                    found[res.back()] = true;
                    if(DFS(res, found, n)) return true;
                    found[res.back()] = false;
                    res.pop_back();
                }
            }
        }
        //cout<<endl;
        return false;
    }
};
