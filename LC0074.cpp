class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[m - 1][n - 1]) return false;
        int start = 0, end = m - 1, pivot;
        while(start < end){
            pivot = (start + end) / 2;
            if(start + 1 == end){
                if(matrix[end][0] <= target){
                    start = end;
                }
                break;
            }
            if(matrix[pivot][0] > target){
                end = pivot - 1;
            }else if(matrix[pivot][0] <= target){
                start = pivot;
            }
        }
        int row = start;
        start = 0; 
        end = n - 1;
        if(target < matrix[row][0] || target > matrix[row][n - 1]) return false;
        while(start < end){
            pivot = (start + end) / 2;
            if(matrix[row][pivot] > target){
                end = pivot - 1;
            }else if(matrix[row][pivot] < target){
                start = pivot + 1;
            }else{
                start = pivot;
                break;
            }
        }
        return (matrix[row][start] == target);
    }
};
