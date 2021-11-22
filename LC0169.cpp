class Solution {
public:
    vector<int> n;
    int majorityElement(vector<int>& nums) {
        vector<int> cur = nums;
        vector<int> s, eq, l;
        while(1){
            int n = cur.size();
            int randnum = cur[rand() % n];
            for(int i = 0; i < n; i++){
                if(cur[i] < randnum){
                    s.push_back(cur[i]);
                }else if(cur[i] > randnum){
                    l.push_back(cur[i]);
                }else{
                    eq.push_back(cur[i]);
                }
            }
            //cout<<randnum<<" "<<eq.size()<<endl;
            if(eq.size() > n / 2){
                return randnum;
            }else if(s.size() > n / 2){
                cur = s;
            }else{
                cur = l;
            }
            s.clear();
            l.clear();
            eq.clear();
        }
        return 0;
    }

};
