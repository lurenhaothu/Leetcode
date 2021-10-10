class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1, p3 = m + n - 1;
        int n1, n2;
        while(p1 >= 0 || p2 >= 0){
            if(p1 >= 0) n1 = nums1[p1];
            else n1 = INT_MIN;
            if(p2 >= 0) n2 = nums2[p2];
            else n2 = INT_MIN;
            if(n1 > n2){
                nums1[p3] = nums1[p1];
                p1--;
                p3--;
            }else{
                nums1[p3] = nums2[p2];
                p2--;
                p3--;
            }
        }
        return;
    }
};
