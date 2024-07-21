class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() ==0 || matrix[0].size() == 0) return false;

        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = m * n - 1;

        while(l <= r){
            int mid = l + (r - l)/2;
            int row = mid / n;
            int c = mid % n;
            if(matrix[row][c] == target) return true;
            else if (target > matrix[row][c]) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};