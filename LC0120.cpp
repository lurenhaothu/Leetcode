class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 1) return triangle[0][0];
        vector<int> *optlast, *optnext, *a;
        vector<vector<int>> OPT(2, vector<int>{});
        optlast = &OPT[0];
        optnext = &OPT[1];
        optlast->push_back(triangle[0][0]);
        int min1 = INT_MAX;
        for(int i = 1; i < triangle.size(); i++){
            optnext->push_back(0);
            optnext->push_back(0);
            for(int j = 0; j <= i; j++){
                if(j == 0) optnext->at(j) = triangle[i][j] + optlast->at(j);
                else if(j == i) optnext->at(j) = triangle[i][j] + optlast->at(j - 1);
                else optnext->at(j) = triangle[i][j] + min(optlast->at(j), optlast->at(j - 1));
                if(i == triangle.size() - 1) min1 = min(optnext->at(j), min1);
                //cout<<optnext->at(j)<<endl;
            }
            a = optnext;
            optnext = optlast;
            optlast = a;
        }
        return min1;
    }
};
